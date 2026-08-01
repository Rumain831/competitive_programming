#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: ダイクストラ法, ポテンシャル
//三角不等式を満たすp(*)を用いて (例:始点からの距離)
//c'(u, v) = c(u, v)+p(u)-p(v) とする。
//すべてのu, vの組に対し c'(u, v)>=0 となるようにdを定めればダイクストラが使える
//s -> t の距離は、 d'(s, t) = d(s, t)+p(s)-p(t)

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> h(n);
  for(int i=0; i<n; i++) cin >> h[i];
  vector<vector<P>> to(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    for(int t=0; t<2; t++){
      ll w=(h[u]<h[v]?2*(h[v]-h[u]):h[v]-h[u]);
      w+=h[u]-h[v];
      to[u].emplace_back(v, w);
      swap(u, v);
    }
  }
  priority_queue<P, vector<P>, greater<P>> pri;
  vector<ll> val(n, 1e18);
  pri.emplace(0, 0);
  val[0]=0;
  while(pri.size()){
    auto [d, idx]=pri.top(); pri.pop();
    if(val[idx]!=d) continue;
    for(auto [ni, w]:to[idx]){
      ll nxt=d+w;
      if(val[ni]>nxt){
        val[ni]=nxt;
        pri.emplace(nxt, ni);
      }
    }
  }
  ll ans=-1e18;
  for(int i=0; i<n; i++) ans=max(ans, -(val[i]-h[0]+h[i]));
  cout << ans << endl;
  return 0;
}