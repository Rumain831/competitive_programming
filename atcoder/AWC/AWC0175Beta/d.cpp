#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 二分探索

int main(void){
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  ll left=0, right=1e18;
  auto judge=[&](ll x){
    ll cnt=0, now=0;
    for(int i=0; i<n; i++){
      if(a[i]>x) return false;
      if(now+a[i]<=x) now+=a[i];
      else cnt++, now=a[i];
    }
    cnt++;
    return cnt<=k;
  };
  while(right-left>1){
    ll mid=(left+right)/2;
    if(judge(mid)) right=mid;
    else left=mid;
  }
  cout << right << endl;
  return 0; 
}