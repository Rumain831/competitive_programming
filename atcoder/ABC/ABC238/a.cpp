#include<iostream>
using namespace std;
using ll = long long;

//Tags: 整数
//頭を使わない解法

int main(void){
  ll n; cin >> n;
  if(n>=20) cout << "Yes" << endl;
  else{
    ll p=(1<<n);
    cout << (p>n*n?"Yes":"No") << endl;
  }
  return 0;
}