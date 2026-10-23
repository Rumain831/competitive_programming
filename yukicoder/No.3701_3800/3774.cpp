#include<iostream>
using namespace std;

//Tags: 回文
//Level: 1.5

int main(void){
  string s; cin >> s;
  int n=s.size(), l=0, r=n-1, ans=0;
  while(l<r) ans+=(s[l]!=s[r]), l++, r--;
  cout << ans << endl;
  return 0; 
}