#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 整数

int main(void){
  ll n, q, m; cin >> n >> q >> m;
  vector<ll> a(n), left(n+2, 1), right(n+2, 1);
  for(int i=0; i<n; i++){
    cin >> a[i]; a[i]%=m;
    left[i+1]=right[i+1]=a[i];
  }
  for(int i=2; i<=n; i++) left[i]*=left[i-1], left[i]%=m;
  for(int i=n; i>=1; i--) right[i]*=right[i+1], right[i]%=m;
  while(q--){
    int x; ll v; cin >> x >> v; v%=m;
    ll ans=left[x-1]*right[x+1]%m*v%m;
    cout << ans << '\n';
  }
  return 0; 
}