#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 貪欲法

int main(void){
  int n, m; cin >> n >> m;
  vector<P> truck;
  for(int i=0; i<n; i++){
    ll e, c; cin >> e >> c;
    truck.emplace_back(e, c);
  }
  sort(begin(truck), end(truck));
  multiset<ll> d;
  for(int i=0; i<m; i++){
    ll x; cin >> x; d.insert(x);
  }
  int ans=0;
  for(int i=0; i<n; i++){
    auto [e, c]=truck[i];
    auto it=d.upper_bound(e);
    if(it==d.begin()) continue;
    it--;
    while(c--&&d.size()){
      ans++;
      it=d.erase(it);
      if(it==d.begin()) break;
      it--;
    }
  }
  cout << ans << endl;
  return 0; 
}