#include<iostream>
#include<set>
using namespace std;

//Tags: 文字列, 全探索

int main(void){
  string s; int k; cin >> s >> k;
  set<string> sub;
  for(int i=0; i<s.size(); i++){
    string t=s.substr(i, k);
    if(t.size()==k) sub.insert(t);
  }
  cout << sub.size() << endl;
  return 0;
}