#include<iostream>
#include<algorithm>
using namespace std;

//Tags: 回文, 全探索
//Level: 2

int f(string s){
  string t=s;
  reverse(begin(t), end(t));
  if(s==t) return (int)s.size();
  else return 0;
}

int main(void){
  string s; cin >> s;
  int n=s.size(), ans=0;
  for(int i=0; i<n; i++)for(int l=1; i+l-1<n&&l<n; l++){
    ans=max(ans,f(s.substr(i, l)));
  }
  cout << ans << endl;
  return 0; 
}