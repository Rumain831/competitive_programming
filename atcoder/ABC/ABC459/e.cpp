#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

ll modpow(ll a, ll b, ll p){
  a%=p;
  ll ans=1;
  while(b>0){
    if(b%2==1) ans=(ans*a)%p;
    b/=2;
    a=(a*a)%p;
  }
  return ans;
}

pair<vector<ll>, vector<ll>> factorial(int n, ll mod){
  vector<ll> fact(n+1, 1), invfact(n+1, 1);
  for(ll i=2; i<=n; i++) fact[i]=fact[i-1]*i%mod;
  invfact[n]=modpow(fact[n], mod-2, mod);
  for(ll i=n-1; i>=1; i--) invfact[i]=invfact[i+1]*(i+1)%mod;
  return {fact, invfact};
}

int main(void){
  int n; cin >> n;
  vector<ll> p(n, -1), c(n), d(n);
  vector<vector<int>> to(n);
  for(int i=1; i<n; i++){
    cin >> p[i], p[i]--;
    to[p[i]].push_back(i);
  }
  for(auto&x:c) cin >> x;
  for(auto&x:d) cin >> x;
  ll mod=998244353;
  vector<ll> used(n), sum(n);
  auto [fact, rev]=factorial(1e6+1, mod);
  auto dfs=[&](auto dfs, int now, int par=-1)->ll {
    ll ans=1;
    for(auto p:to[now])if(p!=par){
      ans*=dfs(dfs, p, now);
      ans%=mod;
      used[now]+=used[p];
      sum[now]+=sum[p];
    }
    sum[now]+=c[now];
    if(sum[now]<used[now]+d[now]) return 0ll;
    for(int i=0; i<d[now]; i++){
      ans*=(ll)(sum[now]-used[now]-i)%mod;
      ans%=mod;
    }
    ans*=rev[d[now]], ans%=mod;
    used[now]+=d[now];
    return ans;
  };
  cout << dfs(dfs, 0) << endl;
  return 0; 
}