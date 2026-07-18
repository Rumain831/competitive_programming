#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main(void){
  int n, k; ll m; cin >> n >> k >> m;
  vector<ll> a(n), sum(n+1);
  for(int i=0; i<n; i++) cin >> a[i], sum[i+1]=sum[i]+a[i];
  ll ans=0;
  for(int i=0; i<n; i++){
    ll now=sum[i];
    ll q=sum.end()-lower_bound(sum.begin(), sum.end(), now+m);
    ll mx1=max(0, n+1-i-k), rem=q;
    ans+=min(mx1, rem);
  }
  cout << ans << endl;
  return 0;
}