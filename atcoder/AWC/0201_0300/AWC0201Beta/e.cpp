#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

//Tags: dp, bitset高速化

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  int sum=0;
  for(auto&x:a) cin >> x, sum+=x;
  bitset<100001> dp(1);
  for(int i=0; i<n; i++) dp|=(dp<<a[i]);
  int ans=1e9;
  for(int i=1; i<sum; i++)if(dp.test(i)) ans=min(ans, abs(i-(sum-i)));
  cout << ans << endl;
  return 0; 
}