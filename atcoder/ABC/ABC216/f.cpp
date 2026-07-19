#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(void){
  int n; cin >> n;
  vector<P> num(n);
  for(int i=0; i<n; i++) cin >> num[i].first;
  for(int i=0; i<n; i++) cin >> num[i].second;
  sort(num.begin(), num.end());
  ll ans=0, mod=998244353;
  vector<ll> dp(5001), sum(5001, 1);
  dp[0]=1;
  for(int i=0; i<n; i++){
    vector<ll> old(5001), sumold(5001);
    swap(old, dp);
    swap(sum, sumold);
    auto [a, b]=num[i];
    if(a>=b) ans+=sumold[a-b], ans%=mod;
    for(int j=0; j<=5000; j++){
      dp[j]+=old[j], dp[j]%=mod;
      if(j+b<=5000) dp[j+b]+=old[j], dp[j+b]%=mod;
    }
    sum[0]=dp[0];
    for(int j=1; j<=5000; j++) sum[j]+=sum[j-1]+dp[j], sum[j]%=mod;
  }
  cout << ans << endl;
  return 0;
}