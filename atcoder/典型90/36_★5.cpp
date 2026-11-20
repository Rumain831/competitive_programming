#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: マンハッタン距離
//解説URL: https://twitter.com/e869120/status/1391886390091075586

int main(void){
  int n, q; cin >> n >> q;
  vector<ll> x(n), y(n), xx(n), yy(n);
  for(int i=0; i<n; i++){
    cin >> x[i] >> y[i];
    xx[i]=x[i]+y[i], yy[i]=x[i]-y[i];
  }
  sort(xx.begin(), xx.end());
  sort(yy.begin(), yy.end());
  while(q--){
    ll p; cin >> p; p--;
    ll nowx=x[p]+y[p], nowy=x[p]-y[p];
    ll ans=-1;
    ans=max(ans, abs(nowx-xx[0]));
    ans=max(ans, abs(nowx-xx.back()));
    ans=max(ans, abs(nowy-yy[0]));
    ans=max(ans, abs(nowy-yy.back()));
    cout << ans << '\n';
  }
  return 0;
}
