#include<iostream>
#include<vector>
using namespace std;

//Tags: あみだくじ, ダブリング

int main(void){
  int n, m, d; cin >> n >> m >> d;
  vector<int> p(n);
  for(int i=0; i<n; i++) p[i]=i;
  for(int i=0; i<m; i++){
    int a; cin >> a; a--;
    swap(p[a], p[a+1]);
  }
  vector db(30, vector<int>(n));
  for(int i=0; i<n; i++) db[0][i]=p[i];
  for(int k=1; k<30; k++)for(int i=0; i<n; i++){
    db[k][i]=db[k-1][db[k-1][i]];
  }
  vector<int> ans(n);
  for(int i=0; i<n; i++){
    int x=d, k=0, now=i;
    while(x){
      if(x&1) now=db[k][now];
      k++, x/=2;
    }
    ans[now]=i+1;
  }
  for(auto p:ans) cout << p << '\n';
  return 0; 
}