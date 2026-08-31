#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: XOR, 主客転倒
//Level: 2.5

int main(void){
  int n; cin >> n;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  ll ans=0, mod=998244353;
  vector cnt(2, vector<ll>(20));
  for(int i=0; i<n; i++)for(int j=0; j<20; j++) cnt[i>>j&1][j]++;
  for(int i=0; i<n; i++){
    ll sum=0;
    for(int j=0; j<20; j++){
      sum+=(1ll<<j)%mod*cnt[(i>>j&1)^1][j], sum%=mod; 
    }
    ans+=a[i]*sum%mod, ans%=mod;
  }
  cout << ans << endl;
  return 0; 
}