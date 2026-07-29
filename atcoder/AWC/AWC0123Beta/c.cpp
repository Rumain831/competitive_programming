#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp, 木, 主客転倒

int main(void){
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for(auto&x:a) cin >> x;
  vector<vector<int>> to(n);
  for(int i=1; i<n; i++){
    int p; cin >> p; p--;
    to[p].push_back(i);
  }
  for(auto&x:b) cin >> x;
  ll ans=0;
  auto dfs=[&](auto dfs, int now, int par=-1)->ll {
    ll sumb=0;
    for(auto p:to[now])if(p!=par){
      sumb+=dfs(dfs, p, now);
    }
    if(now) sumb+=b[now];
    ans+=a[now]*sumb;
    return sumb;
  };
  dfs(dfs, 0);
  cout << ans << endl;
  return 0; 
}