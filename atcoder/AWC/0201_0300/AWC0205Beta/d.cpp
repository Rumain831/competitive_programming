#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: グラフ, 数え上げ

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
  int n, m; cin >> n >> m;
  string s; cin >> s;
  vector<vector<int>> to(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v); swap(u, v);
    to[u].push_back(v);
  }
  ll mod=998244353;
  auto [fact, inv]=factorial(n+1, mod);
  auto nCk=[&](int p, int q){
    return fact[p]*inv[q]%mod*inv[p-q]%mod;
  };
  vector<int> seen(n);
  ll ans=1;
  for(int i=0; i<n; i++){
    if(seen[i]) continue;
    int zero=0, one=0;
    auto dfs=[&](auto dfs, int now, int par=-1)->void {
      if(s[now]=='0') zero++;
      else one++;
      seen[now]++;
      for(auto p:to[now])if(p!=par){
        if(seen[p]) continue;
        dfs(dfs, p, now);
      }
    };
    dfs(dfs, i);
    ans*=nCk(zero+one, one), ans%=mod;
  }
  cout << ans << endl;
  return 0; 
}