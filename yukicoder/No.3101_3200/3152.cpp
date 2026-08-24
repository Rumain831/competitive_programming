#include<iostream>
using namespace std;
using ll = long long;

//Tags: 最大公約数
//Level: 2

ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}

int main(void){
  ll n, a, b; cin >> n >> a >> b;
  ll g=gcd(a, b), lcm=a/g*b;
  ll bai=n/a+n/b-n/lcm;
  cout << n-bai << endl;
  return 0;
}