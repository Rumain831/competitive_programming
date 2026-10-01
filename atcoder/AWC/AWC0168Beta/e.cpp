#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: bitDP, 高速ゼータ変換

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  int mx=(1<<n);
  vector<int> ng(mx);
  for(int i=0; i<m; i++){
    int p, c; cin >> p >> c; p--;
    int now=0;
    while(c--){
      int x; cin >> x; x--;
      now|=(1<<x);
    } 
    ng[now]|=(1<<p);
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<mx; j++)if(!(j>>i&1)){
      ng[j|(1<<i)]|=ng[j];
    }
  }
  vector<bool> dp(mx);
  dp[0]=true;
  for(int i=0; i<mx; i++)if(dp[i]){
    for(int j=0; j<n; j++)if(!(i>>j&1)){
      if(!(ng[i]>>j&1)) dp[i|(1<<j)]=true;
    }
  }
  ll ans=0;
  for(int i=0; i<mx; i++)if(dp[i]){
    ll now=0;
    for(int j=0; j<n; j++)if(i>>j&1) now+=a[j];
    ans=max(ans, now);
  }
  cout << ans << endl;
  return 0; 
}