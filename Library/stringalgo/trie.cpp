#include<iostream>
#include<vector>
using namespace std;

struct TrieNode{
  TrieNode* next[26];
  bool is_end;
  int pass_count;
  TrieNode(){
    for(int i=0; i<26; i++) next[i]=nullptr;
    is_end=false;
    pass_count=0;
  }
};

TrieNode* step(TrieNode* node, char ch){
  int idx=ch-'a';
  if(node->next[idx]==nullptr){
    node->next[idx]=new TrieNode();
  }
  TrieNode* child=node->next[idx];
  child->pass_count++;
  return child;
}

struct Trie{
  TrieNode* root;
  Trie(){
    root=new TrieNode();
  }

  void insert(const string& s){
    TrieNode* now=root;
    for(auto p:s){
      now=step(now, p);
    }
    now->is_end=true;
  }

  bool search(const string& s){
    TrieNode* now=root;
    for(auto ch:s){
      int idx=ch-'a';
      if(now->next[idx]==nullptr) return false;
      else now=now->next[idx];
    }
    return now->is_end;
  }
  
  bool startsWith(const string& s) const {
    TrieNode* now=root;
    for(auto ch:s){
      int idx=ch-'a';
      if(now->next[idx]==nullptr) return false;
      else now=now->next[idx];
    }
    return true;
  }

  int countPrefix(const string& prefix) const {
    TrieNode* now=root;
    for(auto ch:prefix){
      int idx=ch-'a';
      if(now->next[idx]==nullptr) return 0;
      else now=now->next[idx];
    }
    return now->pass_count;
  }

  ~Trie(){
    clear(root);
  }

  void clear(TrieNode* now){
    if(now==nullptr) return;
    for(int i=0; i<26; i++) clear(now->next[i]);
    delete now;
  }

};

int main() {
    Trie trie;

    // 1) 単語をいくつか登録
    vector<string> words = {
        "apple",
        "app",
        "app",
        "application",
        "banana",
        "band",
        "bandit"
    };
    for (const auto& w : words) {
        trie.insert(w);
    }

    // 2) 完全一致検索のテスト
    vector<string> test_search = {
        "app", "apple", "apply", "band", "bandana"
    };
    cout << "=== search ===\n";
    for (const auto& q : test_search) {
        cout << q << ": "
             << (trie.search(q) ? "found" : "not found")
             << "\n";
    }

    // 3) 接頭辞検索 startsWith のテスト
    vector<string> test_prefix = {
        "app", "appl", "ban", "band", "cat"
    };
    cout << "\n=== startsWith ===\n";
    for (const auto& p : test_prefix) {
        cout << p << ": "
             << (trie.startsWith(p) ? "yes" : "no")
             << "\n";
    }

    // 4) 接頭辞付き単語数 countPrefix のテスト
    cout << "\n=== countPrefix ===\n";
    for (const auto& p : test_prefix) {
        cout << p << ": "
             << trie.countPrefix(p)
             << "\n";
    }

    return 0;
}