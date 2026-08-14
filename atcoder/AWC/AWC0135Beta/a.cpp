#include<iostream>
using namespace std;
using ll = long long;

//Tags: 最適化

int main(void){
  ll n, r; cin >> n >> r;
  ll sum=0, mi=1e18;
  for(int i=0; i<n; i++){
    ll x; cin >> x; x+=r;
    sum+=x, mi=min(mi, x);
  }
  cout << sum-mi*n << endl;
  return 0; 
}