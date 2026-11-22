#include<iostream>
#include<vector>
using namespace std;
using ll=long long;

//Tags: パリティ
//解説URL: https://twitter.com/e869120/status/1386814047081746432

int main(void){
  ll n, k; cin >> n >> k;
  vector<int> a(n), b(n);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  ll sum=0;
  for(int i=0; i<n; i++) sum+=abs(a[i]-b[i]);
  if(k>=sum&&k%2==sum%2) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}