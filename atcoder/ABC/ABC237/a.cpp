#include<iostream>
using namespace std;
using ll = long long;

//Tags: bit演算

int main(void){
  ll n; cin >> n;
  ll p=1ll<<31;
  if(-p<=n&&n<p) cout << "Yes" << endl;
  else cout << "No" << endl; 
  return 0;
}