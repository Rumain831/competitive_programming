#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 尺取り法

int main(void){
  ll n, k, x; cin >> n >> k >> x;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  ll ans=0, now=0, r=0;
  for(int i=0; i<n; i++){
    if(r<i) r=i, now=0;
    while(r<n&&now+a[r]<x) now+=a[r++];
    ll len=min(n, i+k)-r;
    ans+=max(len, 0ll);
    now-=a[i];
  }
  cout << ans << endl;
  return 0; 
}