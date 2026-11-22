#include<iostream>
using namespace std;
using ll = long long;

//Tags: 数学
//解説URL: https://twitter.com/e869120/status/1385001057512693762


int main(void){
  ll a, b, c; cin >> a >> b >> c;
  ll x=1;
  while(b) x*=c, b--;
  cout << (a<x?"Yes":"No") << endl;
  return 0; 
}