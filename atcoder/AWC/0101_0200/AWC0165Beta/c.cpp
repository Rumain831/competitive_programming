#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 木dp, 最適化

int main(void){
  int n; cin >> n;
  vector<int> u(n);
  vector<vector<int>> to(n);
  cin >> u[0];
  u[0]=min(u[0], 1);
  for(int i=1; i<n; i++){
    int p; cin >> p >> u[i]; p--;
    to[p].push_back(i);
  }
  ll ans=0;  
  auto dfs=[&](auto dfs, int now, int par=-1)->ll {
    ll mi=2e9;
    for(auto p:to[now])if(p!=par){
      ll val=dfs(dfs, p, now);
      if(val==-1) return -1;
      mi=min(mi, val);
    }
    mi=min<ll>(mi, u[now]);
    if(mi==0) return -1;
    ans+=mi;
    return mi;
  };
  if(dfs(dfs, 0)==-1) cout << -1 << endl;
  else cout << ans << endl;
  return 0; 
}