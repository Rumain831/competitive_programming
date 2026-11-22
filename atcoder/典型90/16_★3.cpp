#include<iostream>
using namespace std;
using ll=long long;

//Tags: 全探索
//解説URL: https://twitter.com/e869120/status/1383189464650981378

int main(void){
  ll n, a, b ,c; cin >> n >> a >> b >> c;
  int ans=10000;
  for(int i=0; i<=9999; i++)for(int j=0; i+j<=9999; j++){
    ll rem=n-a*i-b*j;
    if(rem<0||rem%c) continue;
    ans=min<int>(ans, i+j+rem/c);
  }
  cout << ans << endl;
  return 0;
}