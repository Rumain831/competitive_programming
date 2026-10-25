#include<iostream>
#include<vector>
using namespace std;
using P =pair<int, int>;

//Tags: ゲーム, 全探索

int main(void){
  vector b(2, vector<int>(3));
  vector c(3, vector<int>(2));
  for(int i=0; i<2; i++)for(int j=0; j<3; j++) cin >> b[i][j];
  for(int i=0; i<3; i++)for(int j=0; j<2; j++) cin >> c[i][j];
  vector grid(3, vector<int>(3, -1));
  auto dfs=[&](auto dfs, vector<vector<int>>& a, int step)->P {
    if(step==9){
      int dai=0, ko=0;
      for(int i=0; i<2; i++)for(int j=0; j<3; j++){
        if(a[i][j]==a[i+1][j]) dai+=b[i][j];
        else ko+=b[i][j];
      }
      for(int i=0; i<3; i++)for(int j=0; j<2; j++){
        if(a[i][j]==a[i][j+1]) dai+=c[i][j];
        else ko+=c[i][j];
      }
      return {dai, ko};
    }
    int dai=-1, ko=-1;
    for(int i=0; i<3; i++)for(int j=0; j<3; j++){
      if(a[i][j]!=-1) continue;
      a[i][j]=step%2;
      auto [d, k]=dfs(dfs, a, step+1);
      a[i][j]=-1;
      if(step%2){
        if(ko<k) ko=k, dai=d;
      }
      else{
        if(dai<d) ko=k, dai=d;
      }
    }
    return {dai, ko};
  };
  auto [d, k]=dfs(dfs, grid, 0);
  cout << d << endl << k << endl;
  return 0;
}