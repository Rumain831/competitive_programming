#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: LIS
//Level: 2.5

int f(vector<int> a){
  int n=a.size();
  vector len(2, vector<int>(n));
  for(int i=0; i<2; i++){
    vector<int> dp(n, 2e9);
    for(int j=0; j<n; j++){
      int k=lower_bound(begin(dp), end(dp), a[j])-begin(dp);
      dp[k]=a[j];
      len[i][j]=k;
    }
    reverse(begin(a), end(a));
  }
  reverse(begin(len[1]), end(len[1]));
  int ans=0;
  for(int i=0; i<n; i++) ans=max(ans, min(len[0][i], len[1][i]));
  return ans;
}

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  int ans=0;
  for(int i=0; i<2; i++){
    ans=max(ans, f(a));
    for(auto&x:a) x*=-1;
  }
  cout << ans << endl;
  return 0; 
}