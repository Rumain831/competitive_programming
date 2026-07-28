#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using qu = tuple<int, int, int, int>;

//Tags: ダイクストラ法

int main(void){
  int n, v, ox, oy; cin >> n >> v >> ox >> oy; ox--, oy--;
  vector l(n, vector<int>(n));
  vector mx(n, vector(n, vector<int>(2, -1e9)));
  for(auto&x:l)for(auto&y:x) cin >> y;
  priority_queue<qu> pri;
  pri.emplace(v, 0, 0, 0);
  mx[0][0][0]=v;
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  while(pri.size()){
    auto [hp, t, i, j]=pri.top(); pri.pop();
    if(mx[i][j][t]>hp) continue;
    for(int k=0; k<4; k++){
      int ni=i+di[k], nj=j+dj[k];
      if(ni<0||nj<0||ni>=n||nj>=n) continue;
      int nv=hp-l[ni][nj];
      int nt=t;
      if(nv<=0) continue;
      if(ni==oy&&nj==ox&&t==0) nv*=2, nt=1;
      if(mx[ni][nj][nt]<nv){
        mx[ni][nj][nt]=nv;
        pri.emplace(nv, nt, ni, nj);
      }
    }
  }
  cout << (max(mx[n-1][n-1][0], mx[n-1][n-1][1])<=0?"NO":"YES") << endl;
  return 0; 
}