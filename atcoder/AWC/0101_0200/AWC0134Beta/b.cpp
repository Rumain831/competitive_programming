#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 実装

int main(void){
  ll n, w, m; cin >> n >> w >> m;
  vector<int> l(n), r(n);
  for(int i=0; i<n; i++) cin >> l[i] >> r[i], l[i]--, r[i]--;
  vector<ll> week(7);
  for(int i=0; i<m; i++){
    ll s, e; cin >> s >> e; s--, e--;
    ll len=e-s+1, p=len/7, q=len%7;
    for(int j=0; j<7; j++) week[j]+=p;
    ll st=s%7;
    for(int j=0; j<q; j++) week[(st+j)%7]++;
  }
  for(int i=0; i<n; i++){
    ll ans=0, base=0;
    if(l[i]>r[i]) r[i]+=7;
    base=(r[i]-l[i]+1)*w;
    for(int j=l[i]; j<=r[i]; j++) ans+=week[j%7];
    cout << ans+base << '\n';
  }
  return 0; 
}