#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 二分探索

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> x(n), p(m);
  for(auto&y:x) cin >> y;
  for(auto&y:p) cin >> y;
  p.push_back(-1e18);
  p.push_back(1e18);
  sort(begin(p), end(p));
  for(int i=0; i<n; i++){
    int k=lower_bound(begin(p), end(p), x[i])-begin(p);
    cout << min(abs(x[i]-p[k]), abs(x[i]-p[k-1])) << '\n';
  }
  return 0; 
}