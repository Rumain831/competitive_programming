#include<iostream>
#include<vector>
using namespace std;

int main(void){
  vector<string> grid(4, string(4, '.'));
  vector<string> ans(4, string(4, '.'));
  for(int i=0; i<4; i++)for(int j=0; j<4; j++) cin >> grid[i][j];
  for(int i=0; i<4; i++)for(int j=0; j<4; j++) ans[i][j]=grid[3-i][3-j];
  for(int i=0; i<4; i++)for(int j=0; j<4; j++) cout << ans[i][j] << (j==3?'\n':' ');  
  return 0;
}