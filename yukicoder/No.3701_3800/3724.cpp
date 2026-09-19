#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: grid, 構築
//Level: 2.5

void Print(vector<vector<int>>& ans){
  int n=ans.size(), m=ans[0].size();
  for(int i=0; i<n; i++)for(int j=0; j<m; j++){
    cout << ans[i][j] << (j==m-1?'\n':' ');
  }
  return;
}

void naive(int n, vector<int> r, vector<int> c){
  vector<int> p(n);
  for(int i=0; i<n; i++) p[i]=i;
  {
    int x=c[0];
    bool ng=true;
    for(int i=1; i<n; i++)if(c[i]!=x){ng=false; break;}
    if(ng){
      cout << -1 << endl; return;
    }
  } 
  do{
    vector ans(n, vector<int>(n, -1));
    for(int i=0; i<n; i++)for(int j=0; j<n; j++){
      if(j!=p[i]) ans[i][j]=r[i];
      else ans[i][j]=c[j];
    }
    bool ok=true;
    for(int j=0; j<n; j++){
      int x=0;
      for(int i=0; i<n; i++)if(ans[i][j]==c[j]) x++;
      if(x==1){ok=false; break;}
    }
    if(ok){
      Print(ans); return;
    }
  }while(next_permutation(begin(p), end(p)));
  cout << -1 << endl;
}

void solve(){
  int n; cin >> n;
  vector<int> r(n), c(n);
  for(auto&x:r) cin >> x;
  for(auto&x:c) cin >> x;
  if(n<=2){
    cout << (n==1?1:-1) << endl; return;
  }
  if(n<=4){
    naive(n, r, c); return;
  }
  vector ans(n, vector<int>(n, -1));
  for(int i=0; i<n; i++){
    for(int j=0; j<n-2; j++){
      int nj=(i+j)%n;
      ans[i][nj]=r[i];
    }
  }
  for(int j=0; j<n; j++)for(int i=0; i<n; i++)if(ans[i][j]==-1) ans[i][j]=c[j];
  Print(ans);
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}