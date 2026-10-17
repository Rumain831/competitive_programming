#include<iostream>
using namespace std;

//Tags: 文字列, ランレングス圧縮

int main(void){
  int n; string s; cin >> n >> s;
  int ans=0, now=0;
  for(int i=0; i<n; i++){
    if(s[i]=='R') now++;
    else ans=max(ans, now), now=0;
  }
  ans=max(ans, now);
  cout << ans << endl;
  return 0; 
}