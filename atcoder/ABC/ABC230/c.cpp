#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 条件分岐, grid

int main(void){
  ll n, a, b; cin >> n >> a >> b;
  ll p, q, r, s; cin >> p >> q >> r >> s;
  vector ans(q-p+1, string(s-r+1, '.'));
  for(int i=0; i<q-p+1; i++){
    for(int j=0; j<s-r+1; j++){
      ll nowi=p+i, nowj=r+j;
      //a+k=nowi, b+k=nowj
      if(nowi-a==nowj-b){
        ll k=nowi-a;
        if(max(1-a, 1-b)<=k&&k<=min(n-a, n-b)) ans[i][j]='#';
      }
      //a+k=nowi, b-k=nowj
      if(nowi-a==b-nowj){
        ll k=nowi-a;
        if(max(1-a, b-n)<=k&&k<=min(n-a, b-1)) ans[i][j]='#';
      }
    }
  }
  for(int i=0; i<q-p+1; i++)for(int j=0; j<s-r+1; j++) cout << ans[i] << endl;
  return 0;
}