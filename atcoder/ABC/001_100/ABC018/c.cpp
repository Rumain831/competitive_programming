#include<iostream>
#include<vector>
using namespace std;

//Tags: grid, 累積和

int main(void){
  int r, c, k; cin >> r >> c >> k;
  vector<string> s(r);
  for(auto&x:s) cin >> x;
  vector imos(r+1, vector<int>(c+1));
  for(int i=0; i<r; i++)for(int j=0; j<c; j++)if(s[i][j]=='x'){
    for(int d=-(k-1); d<=k-1; d++){
      int ni=i+d;
      if(ni<0||ni>=r) continue;
      int l=max(0, j-(k-1-abs(d)));
      int r=min(c, j+(k-1-abs(d))+1);
      imos[ni][l]++, imos[ni][r]--;
    }
  }
  for(int i=0; i<r; i++)for(int j=1; j<c; j++) imos[i][j]+=imos[i][j-1];
  int ans=0;
  for(int i=k-1; i<r-k+1; i++)for(int j=k-1; j<c-k+1; j++){
    ans+=(imos[i][j]==0);
  }
  cout << ans << endl;
  return 0;
}