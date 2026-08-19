#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 木, LDS

int f(vector<int>& a){
  reverse(begin(a), end(a));
  vector<int> dp;
  int n=a.size();
  for(int i=0; i<n; i++){
    auto it=lower_bound(begin(dp), end(dp), a[i]);
    if(it==dp.end()) dp.push_back(a[i]);
    else *it=a[i]; 
  }
  return dp.size();
}

int main(void){
  int n, q; cin >> n >> q;
  vector<int> h(n), par(n, -1);
  for(auto&x:h) cin >> x;
  for(int i=1; i<n; i++){
    int p; cin >> p; p--;
    par[i]=p;
  }
  while(q--){
    int u, v; cin >> u >> v; u--, v--;
    vector<int> a, b;
    while(u!=v){
      if(u>v){
        a.push_back(h[u]);
        u=par[u];
      } 
      else{
        b.push_back(h[v]);
        v=par[v];
      }
    }
    a.push_back(h[u]);
    reverse(begin(b), end(b));
    a.insert(end(a), begin(b), end(b));
    cout << f(a) << '\n';
  }
  return 0; 
}