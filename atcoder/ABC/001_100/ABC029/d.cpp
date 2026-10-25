#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 桁dp

int main(void){
  string s; cin >> s;
  vector cnt(10, vector<ll>(2));
  vector dp(10, vector<ll>(2));
  cnt[0][0]=1;
  int m=s.size();
  for(int i=0; i<m; i++){
    vector oldcnt(10, vector<ll>(2));
    vector olddp(10, vector<ll>(2));
    swap(oldcnt, cnt);
    swap(olddp, dp);
    int now=s[i]-'0';
    for(int p=0; p<10; p++)for(int ika=0; ika<2; ika++){
      int r=(ika?9:now);
      for(int j=0; j<=r; j++){
        int nika=(ika|j<now);
        cnt[j][nika]+=oldcnt[p][ika];
        dp[j][nika]+=olddp[p][ika]+(j==1)*oldcnt[p][ika];
      }
    }
  }
  ll ans=0;
  for(int i=0; i<10; i++) ans+=dp[i][0]+dp[i][1];
  cout << ans << endl;
  return 0; 
}