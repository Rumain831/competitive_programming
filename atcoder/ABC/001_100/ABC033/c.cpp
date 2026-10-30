#include<iostream>
using namespace std;

//Tags: 文字列, 構文解析

int main(void){
  string s; cin >> s;
  int n=s.size(), l=0, r=-1, ans=0;
  while(l<n){
    if(l>r) r=l+1;
    while(r<n){
      if(s[r]=='+') break;
      else r+=2;
    }
    int zero=0;
    for(int i=l; i<min(n, r); i++)if(s[i]=='0') zero++;
    if(zero==0) ans++;
    l=r+1;
  }
  cout << ans << endl;
  return 0;
}
