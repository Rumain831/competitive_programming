#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 累積和
//Level: 3

int main(void){
  int n, k; cin >> n >> k;
  vector<int> x(n), y(n), hp(n);
  for(int i=0; i<n; i++) cin >> x[i] >> y[i] >> hp[i];
  int cut=500, mx=cut*2+2;
  vector sum(mx, vector<ll>(mx));
  while(k--){
    int x, y, w, h; ll d; cin >> x >> y >> w >> h >> d;
    int i1=y+cut, i2=i1+h+1, j1=x+cut, j2=j1+w+1;
    i2=min(i2, mx-1), j2=min(j2, mx-1);
    sum[i1][j1]+=d, sum[i1][j2]-=d;
    sum[i2][j1]-=d, sum[i2][j2]+=d;
  }
  for(int i=0; i<mx; i++)for(int j=1; j<mx; j++) sum[i][j]+=sum[i][j-1];
  for(int j=0; j<mx; j++)for(int i=1; i<mx; i++) sum[i][j]+=sum[i-1][j];
  ll ans=0;
  for(int i=0; i<n; i++){
    int ni=y[i]+cut, nj=x[i]+cut;
    ans+=max(0ll, (ll)hp[i]-sum[ni][nj]);
  }
  cout << ans << endl;
  return 0; 
}