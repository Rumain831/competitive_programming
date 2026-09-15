#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 最適化, 貪欲法

int main(void){
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  sort(begin(a), end(a));
  ll ans=a[n-1]-a[0];
  vector<ll> dif;
  for(int i=0; i<n-1; i++) dif.push_back(a[i+1]-a[i]);
  sort(rbegin(dif), rend(dif));
  for(int i=0; i<k-1; i++) ans-=dif[i];
  cout << ans << endl;
  return 0; 
}