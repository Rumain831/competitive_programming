#include<iostream>
using namespace std;
using ll = long long;

//Tags: 二分探索
//Level: 2

void solve(){
  ll n, m; cin >> n >> m;
  ll left=0, right=2e9;
  while(right-left>1){
    ll mid=(left+right)/2;
    ll now=mid*4+(max(0ll, mid*2-m)+3)/4*2;
    if(now<=n) left=mid;
    else right=mid;
  }
  cout << left*3 << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}