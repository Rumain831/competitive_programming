#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 文字列dp

int main(void){
  string s; cin >> s;
  int n=s.size();
  ll mod=1e9+7, ans=1;
  vector dp(n, vector<ll>(2));
  vector<ll> pre(26);
  dp[0][0]=1; dp[0][1]=1; pre[s[0]-'a']=1;
  //dp[i][0]:i-1文字目までの操作で得られる文字列の種類数
  //dp[i][1]:i文字目に印をつけることで初めて得られる文字列の種類数
  for(int i=1; i<n; i++){
    int now=s[i]-'a';
    dp[i][0]+=dp[i-1][0]+dp[i-1][1], dp[i][0]%=mod;
    dp[i][1]+=dp[i-1][0]-pre[now]+mod; dp[i][1]%=mod;
    pre[now]=dp[i-1][0]; //pre[now]+=dp[i][1], pre[now]%=mod; でもok
    ans+=dp[i][1], ans%=mod;
  }
  cout << ans << endl;
  return 0;
}