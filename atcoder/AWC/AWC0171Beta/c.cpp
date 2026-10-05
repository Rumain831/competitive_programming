#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;

//Tags: 累積和

int main(void){
  ll n, k; cin >> n >> k;
  vector<ll> a(n), sum={0};
  for(auto&x:a) cin >> x, sum.push_back(sum.back()+x);
  ll all=sum.back();
  map<ll, ll> cnt;
  ll ans=0;
  cnt[0]++;
  if(all==k) ans++;
  for(int i=0; i<n; i++){
    ll tar=k-all+sum[i+1];
    ans+=cnt[tar];
    cnt[sum[i+1]]++;
  }
  cout << ans << endl;
  return 0; 
}