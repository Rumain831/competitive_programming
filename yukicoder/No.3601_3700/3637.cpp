#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//Tags: 文字列, 部分列
//Level: 2

int main(void){
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<set<int>> idx(26);
  for(int i=0; i<n; i++) idx[s[i]-'a'].insert(i);
  while(q--){
    int T; cin >> T;
    if(T==1){
      int id; char c; cin >> id >> c; id--;
      int oc=s[id]-'a', nc=c-'a';
      idx[oc].erase(id);
      idx[nc].insert(id);
      s[id]=c;
    }
    else{
      string t; cin >> t;
      int m=t.size(), now=-1;
      bool ok=true;
      for(int j=0; j<m; j++){
        auto it=idx[t[j]-'a'].upper_bound(now);
        if(it==end(idx[t[j]-'a'])){
          ok=false; break;
        }
        now=*it;
      }
      cout << (ok?"Yes":"No") << '\n';
    }
  }
  return 0;
}