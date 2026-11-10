#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
using ll = long long;
using tu = tuple<int, int, int>;

//Tags: grid

int main(void){
  int h, w; cin >> h >> w;
  vector a(h, vector<int>(w));
  vector cnt(h, vector<ll>(w, 1));
  vector<tu> b;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    cin >> a[i][j];
    b.emplace_back(a[i][j], i, j);
  }
  sort(begin(b), end(b));
  ll ans=0, mod=1e9+7;
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  for(auto [x, i, j]:b){
    ans+=cnt[i][j], ans%=mod;
    for(int k=0; k<4; k++){
      int ni=i+di[k], nj=j+dj[k];
      if(ni<0||nj<0||ni>=h||nj>=w) continue;
      if(a[i][j]>=a[ni][nj]) continue;
      cnt[ni][nj]+=cnt[i][j];
      cnt[ni][nj]%=mod;
    }
  }
  cout << ans << endl;
  return 0; 
}