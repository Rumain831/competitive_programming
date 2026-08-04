#include<iostream>
using namespace std;

//Tags: ランレングス圧縮

void solve(){
  int n; cin >> n;
  string s; cin >> s;
  int ans=0, now=0;
  for(int i=0; i<n; i++){
    if(s[i]=='*'){
      ans=max(ans, now), now=0;
    }
    else now++;
  }
  ans=max(ans, now);
  cout << (ans+1)/2 << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}