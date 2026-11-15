#include<iostream>
using namespace std;
using ll = long long;

//Tags: 四則演算, タイル

void solve(){
  ll a, b, sx, sy, tx, ty;
  cin >> a >> b >> sx >> sy >> tx >> ty;
  sx+=a*1e8, tx+=a*1e8;
  sy+=b*1e8, ty+=b*1e8;
  ll px=sx/a, qx=tx/a;
  ll py=sy/b, qy=ty/b;
  cout << abs(px-qx)+abs(py-qy) << '\n';
}

int main(void){
  int q; cin >> q;
  while(q--) solve();
  return 0; 
}