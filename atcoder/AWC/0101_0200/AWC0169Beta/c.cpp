#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//Tags: 座標圧縮, グラフ

void solve(vector<int> a, vector<int> b){
  int n=a.size(), m;
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  {
    map<int, int> mp, cc;
    for(int i=0; i<n; i++) mp[a[i]]++;
    for(int i=0; i<n; i++) mp[b[i]]++;
    int c=0;
    for(auto [x, _]:mp) cc[x]=c++;
    for(auto&x:a) x=cc[x];
    for(auto&x:b) x=cc[x];
    m=cc.size();
  }
  vector<vector<int>> to(m);
  for(int i=0; i<n; i++)if(a[i]!=b[i]){
    to[a[i]].push_back(b[i]);
    to[b[i]].push_back(a[i]);
  }
  vector<int> ans(m);
  vector<int> seen(m), path;
  int x=0;
  auto dfs=[&](auto dfs, int now, int par=-1)->void {
    seen[now]=1, x^=1;
    path.push_back(now);
    for(auto p:to[now])if(par!=p){
      if(seen[p]) continue;
      dfs(dfs, p, now);
    }
  };
  for(int i=0; i<n; i++){
    if(seen[a[i]]) continue;
    dfs(dfs, a[i]);
    for(auto p:path) ans[p]=x;
    x=0;
    path.clear();
  }
  for(auto p:a) cout << ans[p] << ' '; cout << '\n';
}

int main(void){
  int n, k, q; cin >> n >> k >> q;
  vector<int> a(k), b(k);
  for(int i=0; i<k; i++) cin >> a[i] >> b[i], a[i]--, b[i]--;
  while(q--){
    int x, p, v; cin >> x >> p >> v; p--, v--;
    if(x==1) a[p]=v;
    else b[p]=v;
    solve(a, b);
  }
  return 0; 
}