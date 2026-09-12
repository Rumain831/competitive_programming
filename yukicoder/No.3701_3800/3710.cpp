#include<iostream>
#include<vector>
using namespace std;

//Tags: 実装, 文字列
//Level: 2.5

int main(void){
  int n, m; cin >> n >> m;
  vector s(n, vector<string>(m));
  for(int i=0; i<n; i++)for(int j=0; j<m; j++) cin >> s[i][j];
  int ans=1e9;
  auto dfs=[&](auto dfs, int step, vector<vector<int>>& cnt)->void {
    if(step==n){
      int now=0;
      for(int i=0; i<m; i++)for(int j=0; j<m; j++) now+=(cnt[i][j]>0);
      ans=min(ans, now);
      return;
    }
    for(int k=0; k<4; k++){
      vector<string> nxt(m, string(m, '.'));
      for(int i=0; i<m; i++)for(int j=0; j<m; j++){
        nxt[i][j]=s[step][j][m-1-i];
        if(nxt[i][j]=='#') cnt[i][j]++;
      }
      s[step]=nxt;
      dfs(dfs, step+1, cnt);
      for(int i=0; i<m; i++)for(int j=0; j<m; j++){
        if(nxt[i][j]=='#') cnt[i][j]--;
      }
    }
    return;
  };
  vector cnt(m, vector<int>(m));
  dfs(dfs, 0, cnt);
  cout << ans << endl;
  return 0; 
}