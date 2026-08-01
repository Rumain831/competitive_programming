#include<iostream>
using namespace std;
using ll = long long;

//Tags: 登場回数

int main(void){
  ll n; cin >> n;
  ll sum=2*n*(n+1);
  for(int i=0; i<4*n-1; i++){
    ll a; cin >> a; sum-=a;
  }
  cout << sum << endl;
  return 0;
}