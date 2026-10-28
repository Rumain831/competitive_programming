#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: LIS

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  vector<int> dp(n, 2e9);
  for(int i=0; i<n; i++){
    int k=upper_bound(begin(dp), end(dp), a[i])-begin(dp);
    dp[k]=a[i];
  }
  int l=lower_bound(begin(dp), end(dp), 2e9)-begin(dp);
  cout << n-l << endl;
  return 0; 
}