#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 木, imos法, DFS

int main(void){
  int n; cin >> n;
  vector<int> a(n-1), b(n-1);
  vector<vector<int>> to(n);
  for(int i=0; i<n-1; i++){
    cin >> a[i] >> b[i]; a[i]--, b[i]--;
    to[a[i]].push_back(b[i]);
    to[b[i]].push_back(a[i]);
  }
  vector<int> depth(n), sub(n);
  vector<ll> ans(n);
  int h=0;
  auto dfs1=[&](auto dfs1, int now, int par=-1)->int {
    sub[now]++;
    depth[now]=h++;
    for(auto p:to[now])if(p!=par){
      sub[now]+=dfs1(dfs1, p, now);
    }
    h--;
    return sub[now];
  };
  dfs1(dfs1, 0);
  for(int i=0; i<n-1; i++){
    int x=a[i], y=b[i];
    if(depth[x]>depth[y]) swap(x, y);
    if(sub[y]>n-sub[y]) ans[y]+=i+1;
    else{
      ans[0]+=i+1, ans[y]-=i+1;
    }
  }
  auto dfs2=[&](auto dfs2, int now, int par=-1)->void {
    for(auto p:to[now])if(p!=par){
      ans[p]+=ans[now];
      dfs2(dfs2, p, now);
    }
  };
  dfs2(dfs2, 0);
  for(int i=0; i<n; i++) cout << ans[i] << ' ';
  return 0; 
}