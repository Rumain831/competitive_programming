#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 数え上げ, dp, 文字列

vector<vector<ll>> comb(int n, ll mod){
  vector nck(n+1, vector<ll>(n+1));
  for(int i=0; i<=n; i++)for(int j=0; j<=i; j++){
    if(j==0||j==i) nck[i][j]=1;
    else nck[i][j]=nck[i-1][j-1]+nck[i-1][j], nck[i][j]%=mod;
  }
  return nck;
}

int main(void){
  ll mod=998244353;
  auto nCk=comb(5001, mod);
  string s; cin >> s;
  int n=s.size();
  vector<ll> cnt(26);
  vector<vector<ll>> dp(27, vector<ll>(n+1));
  for(auto p:s) cnt[p-'a']++;
  dp[0][0]=1;
  for(int i=0; i<26; i++){
    ll all=cnt[i];
    for(int j=0; j<=n; j++){
      for(int k=0; k<=all; k++)if(j+k<=n){
        dp[i+1][j+k]+=dp[i][j]*nCk[j+k][k]%mod, dp[i+1][j+k]%=mod;
      }
    }
  }
  ll ans=0;
  for(int i=1; i<=n; i++) ans+=dp[26][i], ans%=mod;
  cout << ans << endl;
  return 0;
}