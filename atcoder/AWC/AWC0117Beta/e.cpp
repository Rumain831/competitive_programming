#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

ll modpow(ll a, ll b, ll p){
  if(a==0) return 0ll;
  a%=p;
  ll ans=1;
  while(b>0){
    if(b%2==1) ans=(ans*a)%p;
    b/=2;
    a=(a*a)%p;
  }
  return ans;
}

int main(void){
  ll n, k, m; cin >> n >> k >> m;
  vector<ll> a(n);
  for(auto&x:a) cin >> x, x%=m;
  vector<ll> dp(k+1);
  dp[0]=1;
  for(int i=0; i<n; i++){
    vector<ll> old(k+1);
    swap(old, dp);
    ll rev=modpow(a[i], m-2, m);
    for(int j=0; j<=k; j++){
      dp[j]+=old[j], dp[j]%=m;
      if(j+1<=k){
        dp[j+1]+=old[j]*rev%m;
        dp[j+1]%=m;
      }
    }
  }
  cout << dp[k] << endl;
  return 0; 
}