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
  bitset<200001> dp;
  dp.set(0);
  for(int i=0; i<n; i++){
    dp|=(dp<<a[i]);
  }
  int ans=0;
  for(int i=0; i<2e5+1; i++){
    if(dp.test(i)) ans=max(ans, min(i, sum-i));
  }
  cout << ans << endl;
  return 0; 
}