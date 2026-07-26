#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 全探索, DFS

int main(void){
  ll n, x; cin >> n >> x;
  vector<int> l(n);
  vector<vector<ll>> bag(n);
  for(int i=0; i<n; i++){
    cin >> l[i];
    for(int j=0; j<l[i]; j++){
      ll a; cin >> a;
      bag[i].push_back(a);
    }
  }
  int ans=0;
  auto dfs=[&](auto dfs, int step, ll val=1){
    if(step==n){
      if(val==x) ans++;
      return;
    }
    for(int i=0; i<l[step]; i++){
      if(val>x/bag[step][i]) continue;
      dfs(dfs, step+1, val*bag[step][i]);
    }
    return;
  };
  dfs(dfs, 0);
  cout << ans << endl;
  return 0;
}