#include<iostream>
using namespace std;
using ll = long long;

//Tags: 愚直, 最小公倍数
//Level: 1

ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}

int main(void){
  int n, m; cin >> n >> m;
  ll ans=0, mod=998244353;
  for(int i=1; i<=n; i++)for(int j=1; j<=m; j++){
    int g=gcd(i, j);
    ans+=i*j/g;
    ans%=mod;
  }
  cout << ans << endl;
  return 0; 
}