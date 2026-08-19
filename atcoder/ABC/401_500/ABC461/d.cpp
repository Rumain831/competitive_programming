#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main(void){
  int h, w, k; cin >> h >> w >> k;
  vector<string> s(h);
  for(auto&x:s) cin >> x;
  vector sum(h+1, vector<int>(w+1));
  for(int i=0; i<h; i++)for(int j=0; j<w; j++) sum[i+1][j+1]=s[i][j]-'0';
  for(int i=1; i<=h; i++)for(int j=1; j<=w; j++) sum[i][j]+=sum[i][j-1];
  for(int j=1; j<=w; j++)for(int i=1; i<=h; i++) sum[i][j]+=sum[i-1][j];
  auto query=[&](int li, int lj, int ri, int rj){
    return sum[ri][rj]-sum[li-1][rj]-sum[ri][lj-1]+sum[li-1][lj-1];
  };
  ll ans=0;
  for(int i=1; i<=h; i++)for(int j=1; j<=w; j++){
    for(int lj=1; lj<=j; lj++){
      int lowi=1, upi=i;
      if(query(1, lj, i, j)<k) continue;
      if(query(i, lj, i, j)>k) continue;
      if(query(1, lj, i, j)!=k){
        int left=1, right=i;
        while(right-left>1){
          int mid=(left+right)/2;
          if(query(mid, lj, i, j)>k) left=mid;
          else right=mid;
        }
        lowi=right;
      }else lowi=1;
      if(query(i, lj, i, j)!=k){
        int left=1, right=i;
        while(right-left>1){
          int mid=(left+right)/2;
          if(query(mid, lj, i, j)>=k) left=mid;
          else right=mid;
        }
        upi=left;
      }else upi=i;
      if(lowi<=upi) ans+=(ll)(upi-lowi+1);
    }
  }
  cout << ans << endl;
  return 0;
}