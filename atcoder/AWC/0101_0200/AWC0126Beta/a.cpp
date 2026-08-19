#include<iostream>
using namespace std;
using ll = long long;

//Tags: 条件を満たすものの個数

int main(void){
  ll n, d; cin >> n >> d;
  int ans=0;
  for(int i=0; i<n; i++){
    ll x, y; cin >> x >> y;
    ans+=(x*x+y*y>d*d);
  }
  cout << ans << endl;
  return 0; 
}