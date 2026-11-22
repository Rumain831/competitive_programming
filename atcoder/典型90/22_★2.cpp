#include<iostream>
using namespace std;
using ll=long long;

//Tags: 最大公約数
//解説URL: https://twitter.com/e869120/status/1385725481920520193

ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}

int main(void){
  ll a, b, c; cin >> a >> b >> c;
  ll g=gcd(a, b);
  g=gcd(g, c);
  cout << a/g+b/g+c/g-3 << endl;
  return 0;
}