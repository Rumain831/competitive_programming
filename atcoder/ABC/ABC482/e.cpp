#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 木の直径, 数え上げ

int main(void){
  int n; cin >> n;
  vector<vector<int>> to(n);
  for(int i=0; i<n-1; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v); swap(u, v);
    to[u].push_back(v);
  }
  vector<int> c(n);
  for(auto&x:c) cin >> x, x--;
  auto dfs1=[&](auto dfs1, int r, int now, vector<int>& dist, int par=-1)->void {
    for(auto p:to[now])if(p!=par){
      dist[p]=dist[now]+1;
      dfs1(dfs1, r, p, dist, now);
    }
    return;
  };
  vector<int> d1(n), d2(n);
  dfs1(dfs1, 0, 0, d1);
  int ru, rv, mx=-1;
  {
    for(int i=0; i<n; i++)if(mx<d1[i]){
      mx=d1[i], ru=i;
    }
  }
  dfs1(dfs1, ru, ru, d2);
  mx=-1;
  {
    for(int i=0; i<n; i++)if(mx<d2[i]){
      mx=d2[i], rv=i;
    }
  }
  for(auto&x:d1) x=0;
  dfs1(dfs1, rv, rv, d1);
  auto Path=[&](auto Path, int now, vector<int>& ans, int par=-1)->bool {
    ans.push_back(now);
    if(now==rv) return true;
    for(auto p:to[now])if(p!=par){
      if(Path(Path, p, ans, now)) return true;
    }
    ans.pop_back();
    return false;
  };
  vector<int> path;
  Path(Path, ru, path);
  int L=d1[ru];
  if(L&1){
    vector<ll> cnt1(n), cnt2(n);
    for(int i=0; i<n; i++){
      if(d1[i]==L) cnt1[c[i]]++;
      if(d2[i]==L) cnt2[c[i]]++;
    }
    ll ans=0;
    for(int i=0; i<n; i++) ans+=cnt1[i]*cnt2[i];
    cout << ans << endl;
  }
  else{
    int mid=path[L/2];
    ll ans=0;
    vector<ll> cnt(n), col;
    auto dfs=[&](auto dfs, int now, int par=-1)->void {
      bool leaf=true;
      for(auto p:to[now])if(p!=par){
        leaf=false;
        dfs(dfs, p, now);
        if(now==mid){
          for(auto x:col) ans+=cnt[x];
          for(auto x:col) cnt[x]++;
          col.clear();
        }
      }
      if(leaf&&max(d1[now], d2[now])==L) col.push_back(c[now]);
    };
    dfs(dfs, mid);
    cout << ans << endl;
  }
  return 0; 
}