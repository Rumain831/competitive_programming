#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 差分更新
//解説URL: https://twitter.com/e869120/status/1403483256234799105

int main(void){
  int n, q; cin >> n >> q;
  vector<ll> a(n), e(n-1);
  ll ans=0;
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n-1; i++) e[i]=a[i]-a[i+1], ans+=abs(e[i]);
  while(q--){
    int l, r; ll v; cin >> l >> r >> v; l--, r--;
    if(l){
      ans-=abs(e[l-1]);
      e[l-1]-=v;
      ans+=abs(e[l-1]);
    }
    if(r<n-1){
      ans-=abs(e[r]);
      e[r]+=v;
      ans+=abs(e[r]);
    }
    cout << ans << '\n';
  }
  return 0;
}