#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 最適化

int main(void){
  int n; cin >> n;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  a.push_back(*max_element(begin(a), end(a)));
  ll ans=0;
  for(int i=0; i<n-1; i++){
    ans+=max(0ll, a[i+1]-a[i]);
  }
  cout << ans << endl;
  return 0; 
}