#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main(void){
  int n; cin >> n;
  vector<ll> a(n+2);
  for(int i=1; i<=n; i++) cin >> a[i];
  ll ans=-1e18;
  for(int i=1; i<=n; i++){
    ans=max(ans, a[i-1]+a[i]+a[i+1]);
  }
  cout << ans << endl;
  return 0; 
}