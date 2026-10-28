#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: bit全探索, imos法

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  vector<ll> l(m), r(m), c(m), w(m);
  for(int i=0; i<m; i++) cin >> l[i] >> r[i] >> c[i] >> w[i], l[i]--, r[i]--;
  ll ans=1e18;
  int mx=(1<<m);
  for(int i=1; i<mx; i++){
    vector<ll> imos(n+1);
    ll now=0;
    for(int j=0; j<m; j++)if(i>>j&1){
      imos[l[j]]+=c[j];
      imos[r[j]+1]-=c[j];
      now+=w[j];
    }
    bool ok=true;
    for(int j=0; j<n; j++) imos[j+1]+=imos[j];
    for(int j=0; j<n; j++){
      if(a[j]>imos[j]){ok=false; break;}
    }
    if(ok) ans=min(ans, now);
  }
  if(ans==1e18) cout << -1 << endl;
  else cout << ans << endl;
  return 0; 
}