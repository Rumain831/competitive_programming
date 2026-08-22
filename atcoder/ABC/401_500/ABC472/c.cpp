#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 累積和, Simulation

int main(void){
  ll n, m, k; cin >> n >> m >> k;
  vector<ll> a(n), sum(n+1);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  for(int i=0; i<n; i++){
    int l=max(0ll, i-m+1);
    ll now=sum[i]+a[i]-sum[l];
    cout << (now<=k?"Yes":"No") << '\n';
    sum[i+1]=sum[i];
    if(now<=k) sum[i+1]+=a[i];
  }
  return 0; 
}