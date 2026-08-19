#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main(void){
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  ll left=0, right=1e18/k;
  while(right-left>1){
    ll mid=(left+right)/2;
    ll cnt=0;
    for(auto p:a) cnt+=min(p, mid);
    if(cnt>=mid*k) left=mid;
    else right=mid;
  }
  cout << left << endl;
  return 0; 
}