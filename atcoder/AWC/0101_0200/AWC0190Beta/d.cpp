#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp

int main(void){
  int n, c; cin >> n >> c;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  vector<ll> dp(2, -1e18);
  dp[0]=0, dp[1]=a[0];
  for(int i=1; i<n; i++){
    vector<ll> old(2, -1e18);
    swap(old, dp);
    for(int pre=0; pre<2; pre++)for(int now=0; now<2; now++){
      if(pre==0&&now==0) continue;
      ll add=(now==0?0:a[i]+(pre?-c:0));
      dp[now]=max(dp[now], old[pre]+add);
    }
  }
  cout << max(dp[0], dp[1]) << endl;
  return 0; 
}