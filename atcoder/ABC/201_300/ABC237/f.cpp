#include<iostream>
#include<tuple>
#include<map>
using namespace std;
using ll = long long;
using tu = tuple<int, int, int>;

//Tags: LIS

int main(void){
  int n, m; cin >> n >> m;
  ll mod=998244353;
  map<tu, ll> dp;
  dp[tu(1e9, 1e9, 1e9)]=1;
  for(int i=0; i<n; i++){
    map<tu, ll> old;
    swap(old, dp);
    for(auto [_, cnt]:old){
      auto [a, b, c]=_;
      for(int j=1; j<=m; j++){
        tu nxt;
        if(j<=a) nxt=tu(j, b, c);
        else if(j<=b) nxt=tu(a, j, c);
        else if(j<=c) nxt=tu(a, b, j);
        else continue;
        dp[nxt]+=cnt, dp[nxt]%=mod;
      }
    }
  }
  ll ans=0;
  for(auto [x, cnt]:dp){
    auto [a, b, c]=x;
    if(c<=m) ans+=cnt, ans%=mod;
  }
  cout << ans << endl;
  return 0;
}