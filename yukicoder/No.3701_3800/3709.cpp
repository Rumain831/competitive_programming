#include<iostream>
#include<vector>
using namespace std;

//Tags: 二次元累積和
//Level: 2

int main(void){
  int h, w, n; cin >> h >> w >> n;
  vector sum(h+1, vector<int>(w+1));
  while(n--){
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2; r1--, c1--;
    sum[r1][c1]++, sum[r1][c2]--, sum[r2][c1]--, sum[r2][c2]++;
  }
  for(int i=0; i<h; i++)for(int j=0; j<w; j++) sum[i][j+1]+=sum[i][j];
  for(int j=0; j<w; j++)for(int i=0; i<h; i++) sum[i+1][j]+=sum[i][j];
  int ans=0;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++) ans+=(sum[i][j]==0);
  cout << ans << endl;
  return 0; 
}