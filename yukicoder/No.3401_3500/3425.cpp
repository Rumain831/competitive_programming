#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 木
//Level: 2.5

void solve(){
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> to(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v); swap(u, v);
    to[u].push_back(v);
  }
  vector<int> b(n), a(n);
  for(auto&x:b) cin >> x;
  auto dfs=[&](auto dfs, int now, int par=-1)->void {
    ll add=0;
    for(auto p:to[now])if(p!=par){
      dfs(dfs, p, now);
      ll cost=(a[p]<=b[p]?b[p]-a[p]:b[p]+k-a[p]);
      a[p]=(a[p]+cost)%k;
      add+=cost, add%=k;
    }
    a[now]=(a[now]+add)%k;
  };
  dfs(dfs, 0);
  cout << (a[0]==b[0]?"Yes":"No") << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}