#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 原始根

int main(void){
  ll p, mod=998244353; cin >> p;
  ll ans=1;
  vector<ll> prime, g;
  {
    ll n=p-1;
    for(ll i=2; i*i<=p; i++){
      if(n%i) continue;
      prime.push_back(i);
      while(n%i==0){
        n/=i;
      }
    }
    if(n) prime.push_back(n);
  }
  {
    ll n=p-1;
    for(ll i=1; i*i<=n; i++){
      if(n%i) continue;
      g.push_back(i);
      if(i!=n/i) g.push_back(n/i);
    }
    sort(begin(g), end(g));
  }
  unordered_map<ll, ll> cnt;
  for(auto x:g) cnt[x]=(p-1)/x%mod;
  for(auto pr:prime){
    for(auto x:g){
      if(x%pr==0) continue;
      ll now=x;
      while((p-1)/now%pr==0){
        cnt[now]+=mod-cnt[now*pr];
        cnt[now]%=mod;
        now*=pr;
      }
    }
  }
  for(auto x:g){
    ans+=(p-1)/x%mod*cnt[x]%mod;
    ans%=mod;
  }
  cout << ans << endl;
  return 0; 
}
