#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: BFS, bit演算

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<ll> xo(m), c(m);
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      int b; cin >> b;
      xo[i]+=(1<<j)*b;
    }
    cin >> c[i];
  }
  int mx=(1<<n);
  vector<ll> ng(mx), dist(mx, 1e18);
  for(int i=0; i<k; i++){
    int now=0;
    for(int j=0; j<n; j++){
      int b; cin >> b;
      now+=(1<<j)*b;
    }
    ng[now]++;
  }
  priority_queue<P, vector<P>, greater<P>> pri;
  pri.emplace(0, 0);
  dist[0]=0;
  while(pri.size()){
    auto [d, st]=pri.top(); pri.pop();
    if(dist[st]!=d) continue;
    for(int i=0; i<m; i++){
      int nst=st^xo[i];
      if(ng[nst]) continue;
      ll nd=d+c[i];
      if(dist[nst]>nd){
        dist[nst]=nd;
        pri.emplace(nd, nst);
      }
    }
  }
  cout << (dist[mx-1]==1e18?-1:dist[mx-1]) << endl;
  return 0; 
}