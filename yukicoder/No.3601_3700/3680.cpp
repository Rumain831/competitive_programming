#include<iostream>
using namespace std;
using ll = long long;

//Tags: タイル
//Level: 2

void solve(){
  ll sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  if(sx>tx) swap(sx, tx), swap(sy, ty);
  ll now=abs(sy-ty);
  sy=max(sy, ty), ty=sy;
  if(sy>=60){
    cout << now << '\n'; return;
  }
  for(int i=0; i<sy; i++) sx/=2, tx/=2;
  ll ans=1e18; 
  while(tx>sx){
    ans=min(ans, now+tx-sx);
    now+=2;
    sx/=2, tx/=2;
  }
  ans=min(ans, now);
  cout << ans << endl;
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}