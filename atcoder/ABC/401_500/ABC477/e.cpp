#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: 最短距離, ダイクストラ法

int main(void){
  int n, q; cin >> n >> q;
  vector<ll> a(n), b(n), sum(n+1);
  vector<vector<P>> to(n+1);
  for(int i=0; i<n; i++){
    cin >> a[i];
    int u=i, v=(i+1)%n;
    to[u].emplace_back(v, a[i]); swap(u, v);
    to[u].emplace_back(v, a[i]);
    sum[i+1]=sum[i]+a[i];
  }
  for(int i=0; i<n; i++){
    cin >> b[i];
    int u=i, v=n;
    to[u].emplace_back(v, b[i]); swap(u, v);
    to[u].emplace_back(v, b[i]);
  }
  vector<ll> dist(n+1, 1e18);
  priority_queue<P, vector<P>, greater<P>> pri;
  pri.emplace(0, n);
  dist[n]=0;
  while(pri.size()){
    auto [d, id]=pri.top(); pri.pop();
    if(dist[id]!=d) continue;
    for(auto [v, w]:to[id]){
      ll nd=d+w;
      if(dist[v]>nd){
        dist[v]=nd;
        pri.emplace(nd, v);
      }
    }
  }
  ll roop=sum.back();
  while(q--){
    int s, t; cin >> s >> t; s--, t--;
    if(s>t) swap(s, t);
    ll ans=dist[s]+dist[t], d=sum[t]-sum[s];
    if(t!=n){
      ans=min(ans, d);
      ans=min(ans, roop-d);
    }
    cout << ans << '\n';
  }
  return 0; 
}