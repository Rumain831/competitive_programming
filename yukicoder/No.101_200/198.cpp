#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 中央値

int main(void){
  ll b, n; cin >> b >> n;
  ll sum=0;
  vector<ll> c(n);
  for(auto&x:c) cin >> x, sum+=x;
  sort(begin(c), end(c));
  ll ub=(sum+b)/n, ans=0;
  ll x=min(ub, c[n/2]);
  for(int i=0; i<n; i++) ans+=abs(c[i]-x);
  cout << ans << endl;
  return 0; 
}