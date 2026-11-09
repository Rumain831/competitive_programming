#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: dp, 累積

pair<vector<ll>, vector<ll>> f(vector<ll> a){
  int n=a.size();
  vector<ll> l(n+2, 1e18), r(n+2, 1e18);
  for(int i=0; i<n; i++) l[i+1]=min(l[i], a[i]);
  for(int i=n-1; i>=0; i--) r[i+1]=min(r[i+2], a[i]);
  return {l, r};
}

void chmin(ll& a, ll b){a=min(a, b);}

int main(void){
  int n, k; cin >> n >> k;
  vector c(n, vector<ll>(k));
  for(auto&x:c)for(auto&y:x) cin >> y;
  vector<ll> dp(k);
  auto [l, r]=f(dp);
  for(int i=0; i<n; i++){
    vector<ll> old(k, 1e18);
    swap(old, dp);
    for(int j=0; j<k; j++){
      chmin(dp[j], min(l[j], r[j+2])+c[i][j]);
    }
    auto [nl, nr]=f(dp);
    swap(l, nl);
    swap(r, nr);
  }
  cout << *min_element(begin(dp), end(dp)) << endl;
  return 0; 
}