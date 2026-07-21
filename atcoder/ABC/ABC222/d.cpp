#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp, 累積和

int main(void){
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n; i++) cin >> b[i];
  ll mod=998244353;
  vector<ll> dp(3001), sum(3002);
  for(int i=a[0]; i<=b[0]; i++) dp[i]++;
  for(int i=1; i<3002; i++) sum[i]=sum[i-1]+dp[i-1];
  
  for(int i=1; i<n; i++){
    for(int j=0; j<3001; j++){
      if(j>=a[i]&&j<=b[i]) dp[j]=sum[j+1]%mod;
      else dp[j]=0;
    }
    for(int j=1; j<3002; j++) sum[j]=sum[j-1]+dp[j-1], sum[j]%=mod;
  }
  ll ans=0;
  for(int i=a[n-1]; i<=b[n-1]; i++) ans+=dp[i], ans%=mod;
  cout << ans << endl;
  return 0;
}