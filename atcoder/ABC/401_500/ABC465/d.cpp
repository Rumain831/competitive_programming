#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using i128 = __int128_t;

void solve(){
  ll x, y, k; cin >> x >> y >> k;
  ll ans=1e18, c=0;
  i128 now=x;
  while(now>=0){
    if(now>y){
      c++;
      now/=k; continue;
    }
    if(now==y){
      ans=min(ans, c); break;
    }
    i128 l=now, r=now;
    ll cand=c;
    while(r<y){
      l=l*k, r=r*k+k-1;
      cand++;
    }
    if(l<=y&&y<=r) ans=min(ans, cand);
    if(now==0) break;
    now/=k; c++;
  }
  cout << ans << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}