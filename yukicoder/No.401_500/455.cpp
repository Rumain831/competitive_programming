#include<iostream>
#include<vector>
using namespace std;

//Tags: grid, 構築

int main(void){
  int h, w; cin >> h >> w;
  vector<string> s(h);
  for(auto&x:s) cin >> x;
  int i1=-1, j1=-1, i2, j2;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++)if(s[i][j]=='*'){
    if(i1==-1) i1=i, j1=j;
    else i2=i, j2=j;
  }
  int ti, tj;
  if(i1==i2) ti=(i1==0?h-1:0), tj=j1;
  else if(j1==j2) tj=(j1==0?w-1:0), ti=i1;
  else ti=i1, tj=j2;
  s[ti][tj]='*';
  for(auto x:s) cout << x << endl;
  return 0; 
}