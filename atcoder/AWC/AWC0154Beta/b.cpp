#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 実装

ll intsqrt(ll x){ //floor(\sqrt(x))
  ll left=0, right=1e9;
  while(right-left>1){
    ll mid=(left+right)/2;
    if(mid*mid<=x) left=mid;
    else right=mid;
  }
  return left;
}

ll Sq(ll a, ll b){return a*a+b*b;}

int main(void){
  int n, q; cin >> n >> q;
  vector<ll> x(n), y(n), ans(n);
  for(int i=0; i<n; i++) cin >> x[i] >> y[i];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) ans[i]+=intsqrt(Sq(x[i]-x[j], y[i]-y[j]));
  }
  while(q--){
    int c; cin >> c; c--;
    cout << ans[c] << '\n';
  }
  return 0; 
}