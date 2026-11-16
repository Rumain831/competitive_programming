#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using tu = tuple<ll, ll, ll>;

//Tags: 二分探索, ダイクストラ法

int main(void){
  ll n, m, x; cin >> n >> m >> x;
  vector<vector<tu>> to(n);
  for(int i=0; i<m; i++){
    int u, v; ll a, b; cin >> u >> v >> a >> b; u--, v--;
    to[u].emplace_back(v, a, b); swap(u, v);
    to[u].emplace_back(v, a, b);
  }

  auto judge=[&](ll tar){
    vector<ll> dist(n, (ll)1e18+1);
    dist[0]=0;
    priority_queue<P, vector<P>, greater<P>> pri;
    pri.emplace(0, 0);
    while(pri.size()){
      auto [d, id]=pri.top(); pri.pop();
      if(dist[id]!=d) continue;
      for(auto [v, a, b]:to[id]){
        if(b<tar) continue;
        ll nd=d+a;
        if(dist[v]>nd){
          dist[v]=nd;
          pri.emplace(nd, v);
        }
      }
    }
    return dist[n-1]<=x;
  };
  if(!judge(0)){
    cout << -1 << endl; return 0;
  }
  int left=0, right=1e9+1;
  while(right-left>1){
    int mid=(left+right)/2;
    if(judge(mid)) left=mid;
    else right=mid;
  }
  cout << left << endl;
  return 0; 
}