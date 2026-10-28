#include<iostream>
#include<map>
using namespace std;
using ll = long long;

//Tags: 累積和

int main(void){
  ll n, k; cin >> n >> k;
  ll ans=0;
  map<ll, ll> cnt;
  ll sum=0;
  cnt[0]=1;
  for(int i=0; i<n; i++){
    ll x; cin >> x;
    sum+=x;
    ans+=cnt[sum-k];
    cnt[sum]++;
  }
  cout << ans << endl;
  return 0; 
}