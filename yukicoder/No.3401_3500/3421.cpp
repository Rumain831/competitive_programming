#include<iostream>
using namespace std;
using ll = long long;

//Tags: 数学
//Level: 1

void solve(){
  ll a, b, c, d; cin >> a >> b >> c >> d;
  ll D=b*b-3*a*c;
  cout << (a!=0&&D>0?"Yes":"No") << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}