#include<iostream>
using namespace std;
using ll = long long;

//Tags: 最適化

int main(void){
  int n; cin >> n;
  ll mi=1e18, now=0;
  for(int i=0; i<n; i++){
    ll a, b; cin >> a >> b;
    now+=a-b;
    mi=min(mi, now);
  }
  cout << max(0ll, -mi) << endl;
  return 0; 
}