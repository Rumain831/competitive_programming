#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 木, DFS

int main(void){
  int n, k; cin >> n >> k;
  vector<ll> c(n);
  for(auto&x:c) cin >> x;
  vector<vector<int>> to(n);
  for(int i=1; i<n; i++){
    int p; cin >> p; p--;
    to[p].push_back(i);
  }
  vector<int> need(n);
  for(int i=0; i<k; i++){
    int x; cin >> x; x--;
    need[x]++;
  }
  auto dfs=[&](auto dfs, int now, int par=-1)->ll {
    ll ans=0;
    for(auto p:to[now])if(p!=par){
      ans+=dfs(dfs, p, now);
    }
    if(need[now]||ans) ans+=c[now];
    return ans;
  };
  cout << dfs(dfs, 0) << endl;
  return 0; 
}