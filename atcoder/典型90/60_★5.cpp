#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: LIS
//解説URL: https://twitter.com/e869120/status/1402034055734980608

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  vector<int> lis1(n), lis2(n);
  auto lis=[&](vector<int>& b){
    vector<int> dp(n, 1e9), ans(n);
    for(int i=0; i<n; i++){
      int k=lower_bound(begin(dp), end(dp), b[i])-begin(dp);
      dp[k]=b[i];
      ans[i]=k+1;
    }
    return ans;
  };
  lis1=lis(a);
  reverse(begin(a), end(a));
  lis2=lis(a);
  reverse(begin(lis2), end(lis2));
  int ans=-1;
  for(int i=0; i<n; i++){
    ans=max(ans, lis1[i]+lis2[i]-1);
  }
  cout << ans << endl;
  return 0;
}