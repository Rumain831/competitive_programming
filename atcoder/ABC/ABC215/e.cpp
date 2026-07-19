#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main(void){
  int n; cin >> n;
  string s; cin >> s;
  int m=10;
  int mx=(1<<m);
  vector dp(mx, vector<ll>(m));
  ll mod=998244353;
  for(int i=0; i<n; i++){
    vector old(mx, vector<ll>(m));
    swap(old, dp);
    int now=s[i]-'A';
    dp[1<<now][now]=1;
    for(int j=0; j<mx; j++)for(int k=0; k<m; k++){
      dp[j][k]+=old[j][k]; dp[j][k]%=mod;
      if(k==now||!((j>>now)&1)) dp[j|(1<<now)][now]+=old[j][k], dp[j|(1<<now)][now]%=mod;
    }
  }
  ll ans=0;
  for(int i=0; i<mx; i++)for(int j=0; j<m; j++) ans+=dp[i][j], ans%=mod;
  cout << ans << endl;
  return 0;
}