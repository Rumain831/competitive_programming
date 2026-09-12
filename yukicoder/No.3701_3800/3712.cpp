#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: ダイクストラ法
//Level: 2.5

ll get(ll t, ll a, ll b, ll c){
  if(t==0) t++;
  ll k=(t+a-1)/a, ans=k*a;
  if(k%b==0) ans+=c;
  return min(ans, (k+1)*a);
}

int main(void){
  int n, m; cin >> n >> m;
  vector<vector<P>> to(n);
  for(int i=0; i<m; i++){
    int u, v; ll w; cin >> u >> v >> w; u--, v--;
    to[u].emplace_back(v, w); swap(u, v);
    to[u].emplace_back(v, w);
  }
  vector<ll> a(n), b(n), c(n);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  for(auto&x:c) cin >> x;
  vector<ll> dist(n, 1e18);
  priority_queue<P, vector<P>, greater<P>> pri;
  pri.emplace(0, 0);
  dist[0]=0;
  while(pri.size()){
    auto [d, id]=pri.top(); pri.pop();
    if(dist[id]!=d) continue;
    for(auto [v, w]:to[id]){
      ll nd=get(d, a[id], b[id], c[id])+w;
      if(dist[v]>nd){
        dist[v]=nd;
        pri.emplace(nd, v);
      }
    }
  }
  cout << dist[n-1] << endl;
  return 0; 
}