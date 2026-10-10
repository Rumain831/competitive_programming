#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: Simulation
//遅延伝播セグ木でも解ける

int main(void){
  int n; cin >> n;
  ll mi[2]={(ll)2e9, (ll)2e9};
  ll all[2]={0, 0};
  vector<ll> c(n);
  for(int i=0; i<n; i++){
    cin >> c[i];
    mi[i&1]=min(mi[i&1], c[i]);
  }
  int q; cin >> q;
  ll ans=0;
  while(q--){
    int t; cin >> t;
    if(t==1){
      ll x, a; cin >> x >> a; x--;
      if(c[x]>=all[x&1]+a) c[x]-=a, ans+=a;
      mi[x&1]=min(mi[x&1], c[x]);
    }
    else if(t==2){
      ll a; cin >> a;
      if(mi[0]>=all[0]+a) ans+=a*((n+1)/2), all[0]+=a;
    }
    else{
      ll a; cin >> a;
      if(mi[0]>=all[0]+a&&mi[1]>=all[1]+a){
        ans+=a*n, all[0]+=a, all[1]+=a;
      }
    }
  }
  cout << ans << endl;
  return 0;
}