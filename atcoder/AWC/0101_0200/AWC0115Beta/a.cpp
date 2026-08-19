#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main(void){
  int n; cin >> n;
  vector<ll> a(n);
  ll sum=0;
  for(auto&x:a) cin >> x, sum+=x;
  ll mx=*max_element(begin(a), end(a));
  cout << mx*n-sum << endl;
  return 0; 
}