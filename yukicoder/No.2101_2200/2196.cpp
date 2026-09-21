#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 全探索
//Level: 1.5

int main(void){
  int n; cin >> n;
  vector<ll> a(2*n), b(2*n), x(n), y(n);
  for(auto&p:a) cin >> p;
  for(auto&p:b) cin >> p;
  for(auto&p:x) cin >> p;
  for(auto&p:y) cin >> p;
  ll ans=0, mx=4;
  for(int i=0; i<n; i++){
    ll add=0;
    for(int j=0; j<mx; j++){
      int c1=(j&1), c2=((j>>1)&1);
      ll now=(c1?a[2*i]:b[2*i])+(c2?a[2*i+1]:b[2*i+1])+(c1==c2?x[i]:y[i]);
      add=max(add, now);
    }
    ans+=add;
  }
  cout << ans << endl;
  return 0; 
}