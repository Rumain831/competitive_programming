#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;

//Tags: 数え上げ, 累積和

int main(void){
  int n; ll k; cin  >> n >> k;
  vector<ll> a(n), sum(n+1);
  map<ll, ll> cnt; 
  for(int i=0; i<n; i++){
    cin >> a[i]; sum[i+1]=sum[i]+a[i];
    cnt[sum[i+1]]++;
  }
  ll ans=0;
  for(int i=1; i<=n; i++){
    ans+=cnt[k+sum[i-1]];
    cnt[sum[i]]--;
  }
  cout << ans << endl;
  return 0;
}