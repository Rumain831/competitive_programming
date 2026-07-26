#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 順列全探索, グラフ

int main(void){
  int n, m; cin >> n >> m;
  vector ea(n, vector<int>(n));
  vector eb(n, vector<int>(n));
  for(int i=0; i<m; i++){int a, b; cin >> a >> b; a--, b--; ea[a][b]=ea[b][a]=1;}
  for(int i=0; i<m; i++){int a, b; cin >> a >> b; a--, b--; eb[a][b]=eb[b][a]=1;}
  vector<int> p(n);
  for(int i=0; i<n; i++) p[i]=i;
  do{
    vector now(n, vector<int>(n));
    for(int i=0; i<n-1; i++)for(int j=i+1; j<n; j++){
      now[i][j]=now[j][i]=eb[p[i]][p[j]];
    }
    if(ea==now){
      cout << "Yes" << endl; return 0;
    }
  }while(next_permutation(p.begin(), p.end()));
  cout << "No" << endl;
  return 0; 
}