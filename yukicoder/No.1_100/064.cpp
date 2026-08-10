#include<iostream>
using namespace std;
using ll = long long;

//Tags: XOR, 周期性

// 0000
// 0110110
// 10110110
// 110110

int main(void){
  ll f[2], n; cin >> f[0] >> f[1] >> n;
  if(n<2){
    cout << f[n] << endl; return 0;
  }
  ll ans=0;
  for(int i=0; i<60; i++){
    int b[2];
    for(int j=0; j<2; j++) b[j]=(f[j]>>i&1);
    if(b[0]==0&&b[1]==0) continue;
    ll m;
    if(b[0]&&b[1]) m=n;
    else if(b[0]) m=n-2;
    else m=n-1;  
    if(m%3!=2) ans+=(1ll<<i);
  }
  cout << ans << endl;
  return 0; 
}