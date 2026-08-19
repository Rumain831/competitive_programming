#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: グラフ

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> deg(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    deg[u]+=v+1, deg[v]+=u+1;
  }
  cout << *max_element(begin(deg), end(deg)) << endl;
  return 0; 
}