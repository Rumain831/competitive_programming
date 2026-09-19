#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<int, int>;

//Tags: grid, 構築
//Level: 2.5
//実験に使ったコードも載せておきます。

bool reach(int n, vector<string>& s){
  vector ok(n, vector<int>(n));
  queue<P> bfs;
  bfs.emplace(0, 0);
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  while(bfs.size()){
    auto [i, j]=bfs.front(); bfs.pop();
    if(ok[i][j]) continue;
    ok[i][j]=1;
    for(int k=0; k<4; k++){
      int ni=i+di[k], nj=j+dj[k];
      if(ni<0||nj<0||ni>=n||nj>=n) continue;
      if(s[ni][nj]=='#') continue;
      bfs.emplace(ni, nj);
    }
  }
  return ok[n-1][n-1];
}

void Print(vector<string>& s){
  for(auto&p:s) cout << p << endl;
}


void exp(int n){
  ll mx=(1ll<<(n*n));
  map<vector<string>, bool> goal;
  set<vector<string>> all;
  for(ll i=0; i<mx; i++){
    if((i&1)||(i>>(n*n-1)&1)) continue;
    vector<string> now(n, string(n, '.'));
    for(int j=0; j<n; j++)for(int k=0; k<n; k++){
      int p=j*n+k;
      if(i>>p&1) now[j][k]='#';
    }
    goal[now]=reach(n, now);
    all.insert(now);
  }
  for(ll i=0; i<mx; i++){
    if((i&1)||(i>>(n*n-1)&1)) continue;
    vector<string> now(n, string(n, '.'));
    for(int j=0; j<n; j++)for(int k=0; k<n; k++){
      int p=j*n+k;
      if(i>>p&1) now[j][k]='#';
    }
    bool alice_win=true;
    {
      for(int li=1; li<n-1; li++){
        for(int ri=li; ri<n-1; ri++){
          vector<string> t=now;
          for(int ni=li; ni<=ri; ni++)for(int nj=0; nj<n; nj++) t[ni][nj]=(t[ni][nj]=='.'?'#':'.');
          if(!goal[t]){
            alice_win=false; break;
          }
        }
        if(!alice_win) break;
      }
    }
    if(!alice_win) continue;
    {
      for(int lj=1; lj<n-1; lj++){
        for(int rj=lj; rj<n-1; rj++){
          vector<string> t=now;
          for(int ni=0; ni<n; ni++)for(int nj=lj; nj<=rj; nj++) t[ni][nj]=(t[ni][nj]=='.'?'#':'.');
          if(!goal[t]){
            alice_win=false; break;
          }
        }
      }
    }
    if(alice_win){
      for(auto p:now) cout << p << endl; return;
    }
  }
  cout << "Nothing" << endl;
}

int main(void){
  //exp(4);
  int n; cin >> n;
  for(int i=0; i<n; i++)for(int j=0; j<n; j++){
    cout << (n-2<=i+j&&i+j<=n-1?'#':'.');
    if(j==n-1) cout << endl;
  }
  return 0; 
}