#include<iostream>
#include<array>
#include<vector>
#include<queue>
using namespace std;

struct Aho{
  static constexpr int sigma=26;
  char base='a';
  struct Node{
    array<int, sigma> next;
    int fail_link;
    bool bad;
    Node():fail_link(0), bad(false){
      next.fill(-1);
    }
  };

  vector<Node> trie;
  Aho(){
    trie.emplace_back();
  }

  int add(const string& s){
    int v=0;
    for(auto c:s){
      int now=c-base;
      if(trie[v].next[now]==-1){
        trie[v].next[now]=(int)trie.size();
        trie.emplace_back();
      }
      v=trie[v].next[now];
    }
    trie[v].bad=true;
    return v;
  }

  void build(){
    queue<int> bfs;
    for(int c=0; c<sigma; c++){
      int nxt=trie[0].next[c];
      if(nxt==-1) trie[0].next[c]=0;
      else{
        trie[nxt].fail_link=0;
        bfs.push(nxt);
      }
    }
    while(bfs.size()){
      int now=bfs.front(); bfs.pop();
      for(int c=0; c<sigma; c++){
        int nxt=trie[now].next[c];
        if(nxt==-1) trie[now].next[c]=trie[trie[now].fail_link].next[c];
        else{
          trie[nxt].fail_link=trie[trie[now].fail_link].next[c];
          trie[nxt].bad|=trie[trie[nxt].fail_link].bad;
          bfs.push(nxt);
        }
      }
    }
  }

  int move(int now, char c){
    int idc=c-base;
    return trie[now].next[idc];
  }

  int move_id(int now, int idc){
    return trie[now].next[idc];
  }

};

int main(void){
  return 0;
}