#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

void solve(){
  int n; cin >> n;
  string s; cin >> s;
  vector<int> t(n);
  for(int i=0; i<n; i++) t[i]=(s[i]=='R');
  vector<ll> x(n), y(n-1);
  for(auto&p:x) cin >> p;
  for(auto&p:y) cin >> p;
  vector dp(2, vector<ll>(n, -1e18));
  for(int i=0; i<2; i++) dp[i][0]=(t[0]==i?0:-x[0]);
  for(int i=1; i<n; i++){
    for(int pre=0; pre<2; pre++)for(int now=0; now<2; now++){
      ll add=(t[i]==now?0:-x[i])+(pre&&now==0?y[i-1]:0);
      dp[now][i]=max(dp[now][i], dp[pre][i-1]+add);
    }
  }
  cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}