#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<int, int>;

//Tags: 数え上げ, グラフ, DFS
//Level: 2.5

int main(void){
  int n, q; cin >> n >> q;
  vector<vector<P>> to(n);
  vector<int> col(n, -1);
  for(int i=0; i<q; i++){
    int t, a, b; cin >> t >> a >> b; a--, b--;
    to[a].emplace_back(b, t); swap(a, b);
    to[a].emplace_back(b, t);
  }
  auto dfs=[&](auto dfs, int now, int c=0)->bool {
    col[now]=c;
    for(auto [p, t]:to[now]){
      if(col[p]==-1){
        if(!dfs(dfs, p, c^t)) return false;
      }
      else{
        if(col[p]!=(c^t)) return false;
      }
    }
    return true;
  };
  ll ans=1, mod=998244353;
  for(int i=0; i<n; i++){
    if(col[i]!=-1) continue;
    if(!dfs(dfs, i)) ans=0;
    else ans*=2, ans%=mod;
  }
  cout << ans << endl;
  return 0; 
}