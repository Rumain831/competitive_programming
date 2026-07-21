#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(void){
  int n, m; cin >> n >> m;
  vector<P> tree;
  for(int i=0; i<n; i++){
    ll d, v; cin >> d >> v;
    tree.emplace_back(d, v);
  }
  vector<ll> l(m);
  for(auto&x:l) cin >> x;
  sort(begin(tree), end(tree));
  sort(begin(l), end(l));
  priority_queue<ll> pri;
  int id=0;
  ll ans=0;
  for(int i=0; i<m; i++){
    ll tar=l[i];
    while(id<n){
      auto [d, v]=tree[id];
      if(tar>=d){
        pri.emplace(v); id++;
      }
      else break;
    }
    if(pri.size()){
      ans+=pri.top(); pri.pop();
    }
  }
  cout << ans << endl;
  return 0; 
}