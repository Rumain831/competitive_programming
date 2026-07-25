#include<iostream>
using namespace std;

//Tags: 愚直, 回文, 文字列

int main(void){
  string s; cin >> s;
  string t;
  for(auto p:s) t+=p, t+='*';
  t.pop_back();
  int ans=0;
  int n=t.size();
  for(int i=0; i<n; i++){
    int l=i, r=i, cnt=0;
    while(l>=0&&r<n){
      if(t[l]==t[r]){
        if(t[i]!='*') ans++;
        l--, r++; continue;
      }
      if(cnt) break;
      if(t[i]!='*') ans++;
      cnt++; l--, r++;
    }
  }
  cout << ans << endl;
  return 0; 
}