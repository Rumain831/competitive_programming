#include<iostream>
using namespace std;
using ll = long long;
using i128 = __int128_t;

//Tags: 多倍長整数
//Level: 1.5

ll modpow(i128 a, ll b, ll p){
  a%=p;
  i128 ans=1;
  while(b>0){
    if(b%2==1) ans=(ans*a)%p;
    b/=2;
    a=(a*a)%p;
  }
  return (ll)ans;
}

int main(void){
  ll m; cin >> m;
  cout << modpow(2, 128, m) << endl;
  return 0; 
}