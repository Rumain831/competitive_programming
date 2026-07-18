#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using ll = long long;

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> a(n);
  multiset<ll> b;
  for(auto&x:a) cin >> x;
  for(int i=0; i<m; i++){
    ll x; cin >> x; b.insert(x);
  }
  sort(a.begin(), a.end());
  int ans=0;
  for(int i=0; i<n; i++){
    auto it=b.upper_bound(2ll*a[i]);
    if(it==b.begin()) continue;
    it--;
    ans++;
    b.erase(it);
  }
  cout << ans << endl;
  return 0; 
}