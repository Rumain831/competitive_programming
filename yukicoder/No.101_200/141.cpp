#include<iostream>
using namespace std;
using ll = long long;

//Tags: Simulation, 整数
//Level: 2

int main(void){
  ll m, n; cin >> m >> n;
  ll ans=0;
  while(m!=n){
    if(m<n) ans++, swap(m, n);
    if(m%n==0){
      m/=n, n=1; ans+=m-1; break;
    }
    ll r=m/n;
    m-=r*n; ans+=r;
  }
  cout << ans << endl;
  return 0; 
}