#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 円環

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  a.insert(end(a), begin(a), end(a));
  ll ans=-1e18, now=0;
  for(int i=0; i<m-1; i++) now+=a[i];
  for(int i=m-1; i<n+n; i++){
    now+=a[i];
    ans=max(ans, now);
    now-=a[i-m+1];
  }
  cout << ans << endl;
  return 0; 
}