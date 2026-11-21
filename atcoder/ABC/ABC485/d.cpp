#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 数え上げ, 文字列

int f(string& s){
  int n=s.size();
  int pos[3]={-1, -1, -1};
  for(int i=0; i<n; i++){
    int now=s[i]-'A';
    pos[now]=i;
  }
  return min({pos[0], pos[1], pos[2]});
}

int main(void){
  int n; cin >> n;
  string s; cin >> s;
  int lim=f(s);
  if(lim==-1){
    cout << 0 << endl; return 0;
  }
  vector nxt(n+1, vector<int>(3, -1));
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<3; j++) nxt[i][j]=nxt[i+1][j];
    int now=s[i]-'A';
    nxt[i][now]=i;
  }
  int st=max({nxt[0][0], nxt[0][1], nxt[0][2]});
  ll ans=0;
  for(int i=st; i<n; i++){
    int r=max({nxt[i+1][0], nxt[i+1][1], nxt[i+1][2]});
    if(r>lim||r==-1) break;
    ans+=lim-r;
  }
  cout << ans << endl;
  return 0; 
}