#include<iostream>
#include<vector>
using namespace std;

//Tags: 全探索, grid

int main(void){
  int n; cin >> n;
  vector<string> s(n), t(n);
  int ti=-1, tj;
  for(int i=0; i<n; i++) cin >> s[i];
  for(int i=0; i<n; i++){
    cin >> t[i];
    for(int j=0; j<n; j++)if(ti==-1){
      if(t[i][j]=='#') ti=i, tj=j;
    }
  }
  for(int i=0; i<4; i++){
    vector<string> now(n, string(n, '.'));
    vector<string> to(n, string(n, '.'));
    for(int j=0; j<n; j++)for(int k=0; k<n; k++) now[j][k]=s[k][n-1-j];
    int si=-1, sj;
    for(int j=0; j<n; j++)for(int k=0; k<n; k++)if(si==-1&&now[j][k]=='#') si=j, sj=k;
    bool ok=true;
    int di=ti-si, dj=tj-sj;
    for(int j=0; j<n; j++)for(int k=0; k<n; k++)if(now[j][k]=='#'){
      int ni=j+di, nj=k+dj;
      if(ni<0||nj<0||ni>=n||nj>=n){
        ok=false; break;
      }
      to[ni][nj]='#';
    }
    swap(s, now);
    if(ok&&to==t){
      cout << "Yes" << endl; return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}