#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: bit全探索, Simulation

int n;

int f(vector<string>& p){
  vector<P> pl;
  for(int i=0; i<n; i++){
    int cnt=0;
    for(int j=0; j<n; j++){
      cnt+=(p[i][j]=='o');
    }
    pl.emplace_back(cnt, i);
  }
  sort(rbegin(pl), rend(pl));
  int id=0, c=1;
  while(id<n){
    int now=pl[id].first;
    while(id<n){
      auto [w, i]=pl[id];
      if(now!=w) break;
      if(i==0) return c;
      id++;
    }
    c++;
  }
  return n;
}

int main(void){
  cin >> n;
  vector<string> s(n);
  for(auto&x:s) cin >> x;
  vector<P> emp;
  for(int i=0; i<n-1; i++)for(int j=i+1; j<n; j++){
    if(s[i][j]=='-') emp.emplace_back(i, j);
  }
  int m=emp.size(), mx=(1<<m);
  int ans=1e9;
  for(int i=0; i<mx; i++){
    for(int j=0; j<m; j++){
      auto [ni, nj]=emp[j];
      if(i>>j&1) s[ni][nj]='o', s[nj][ni]='x';
      else s[ni][nj]='x', s[nj][ni]='o';
    }
    ans=min(ans, f(s));
    for(int j=0; j<m; j++){
      auto [ni, nj]=emp[j];
      s[ni][nj]=s[nj][ni]='-';
    }
  }
  cout << ans << endl;
  return 0; 
}