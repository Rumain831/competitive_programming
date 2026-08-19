#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;

//Tags: 整数, 素因数分解, 約数

int main(void){
  ll n, k; cin >> n >> k;
  ll mod=998244353;
  vector<ll> yakusu(1e6+1, -1), prime;
  for(int i=2; i<=1e6; i++){
    if(yakusu[i]!=-1) continue;
    int copy=i;
    prime.push_back(i);
    while(copy<=1e6){
      if(yakusu[copy]==-1) yakusu[copy]=i;
      copy+=i;
    }
  }
  ll m=prime.size();
  vector<ll> cnt(m);
  map<ll, ll> big;
  auto f=[&](ll left, ll right, int sign){
    vector<ll> list;
    for(ll i=left; i<=right; i++) list.push_back(i);
    int mm=list.size();
    for(int i=0; i<m; i++){
      ll p=prime[i];
      //ps>=left
      ll s=(left+p-1)/p, x=p*s;
      ll id=x-left;
      while(id<mm){
        while(list[id]%p==0) list[id]/=p, cnt[i]+=sign;
        id+=p;
      }
    }
    for(auto p:list)if(p>1) big[p]+=sign;
  };
  f(n-k+1, n, 1), f(1, k, -1);
  ll ans=1;
  for(auto p:cnt) ans*=p+1, ans%=mod;
  for(auto [_, p]:big) ans*=p+1, ans%=mod;
  cout << ans << endl;
  return 0;
}