#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 累積和, 筆算

int main(void){
  string x; cin >> x;
  int n=x.size();
  vector<ll> sum(n+1);
  for(int i=0; i<n; i++) sum[i+1]=sum[i]+(x[i]-'0');
  reverse(sum.begin(), sum.end());
  vector<ll> ans(n+1);
  for(int i=0; i<n; i++){
    ans[i]=sum[i]%10;
    sum[i+1]+=sum[i]/10;
  }
  ans[n]=sum[n];
  if(ans[n]==0) ans.pop_back();
  reverse(ans.begin(), ans.end());
  for(auto p:ans) cout << p;
  return 0;
}