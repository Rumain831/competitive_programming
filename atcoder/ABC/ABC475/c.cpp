#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 全探索, 累積和

int main(void){
  ll n, s, L; cin >> n >> s >> L; s--;
  vector<ll> dist(n);
  for(int i=0; i<n-1; i++){
    ll a; cin >> a;
    dist[i+1]=dist[i]+a;
  }
  int ans=1;
  for(int l=0; l<=s; l++)for(int r=s; r<n; r++){
    ll d=dist[r]-dist[l]+min(dist[s]-dist[l], dist[r]-dist[s]);
    if(d<=L) ans=max(ans, r-l+1);
  }
  cout << ans << endl;
  return 0; 
}