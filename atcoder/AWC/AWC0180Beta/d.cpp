#include<iostream>
#include<vector>
#include<set>
using namespace std;
using P = pair<int, int>;

//Tags: grid, dp

int main(void){
  int n, k; cin >> n >> k;
  vector a(n, vector<int>(n));
  vector seen(n, vector<int>(n));
  vector<vector<int>> point;
  int mx=16;
  vector f(mx, vector<int>(5));
  for(int base=0; base<mx; base++){
    for(int aft=0; aft<mx; aft++){
      int p=(base^aft);
      int ch=__builtin_popcount(p);
      int y=(aft&1), rot=aft/2+(1<<3)*y;
      int po=0;
      for(int q=0; q<4; q++){
        if((aft>>q&1)&&(rot>>q&1)) po++;
      }
      f[base][ch]=max(f[base][ch], po);
    }
  }
  for(auto&x:a)for(auto&y:x) cin >> y;
  for(int i=0; i<n; i++)for(int j=0; j<n; j++){
    if(seen[i][j]) continue;
    //4点列挙, 01列挙
    int ni=i, nj=j;
    int bit=0;
    set<P> now;
    for(int p=0; p<4; p++){
      now.emplace(ni, nj);
      seen[ni][nj]++;
      bit=bit*2+a[ni][nj];
      int nxi=nj, nxj=n-1-ni;
      ni=nxi, nj=nxj;
    }
    //全部同じ点なら例外処理
    if(now.size()==1){
      vector<int> po(5);
      if(a[i][j]) po[0]=1;
      else po[1]=1;
      point.push_back(po);
      continue;
    }
    //塗る個数ごとに得点
    point.push_back(f[bit]);
  }
  int m=point.size();
  cout << m << endl;
  vector dp(m+1, vector<int>(k+1, -1e9));
  dp[0][0]=0;
  for(int i=0; i<m; i++){
    for(int j=0; j<=k; j++)if(dp[i][j]>=0){
      for(int p=0; p<5; p++)if(j+p<=k){
        dp[i+1][j+p]=max(dp[i+1][j+p], dp[i][j]+point[i][p]);
      }
    }
  }
  int ans=-1;
  for(int i=0; i<=m; i++)for(int j=0; j<=k; j++) ans=max(ans, dp[i][j]);
  cout << ans << endl;
  return 0; 
}