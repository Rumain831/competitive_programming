#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 順列

int main(void){
  int n, q; cin >> n >> q;
  vector<int> p(n), inv(n);
  for(int i=0; i<n; i++){
    cin >> p[i]; p[i]--;
    inv[p[i]]=i;
  }
  while(q--){
    int t; cin >> t;
    if(t==1){
      int x, y; cin >> x >> y; x--, y--;
      int vx=p[x], vy=p[y];
      swap(p[x], p[y]);
      swap(inv[vx], inv[vy]);
    }
    else swap(p, inv);
  }
  for(auto x:p) cout << x+1 << ' ';
  return 0; 
}