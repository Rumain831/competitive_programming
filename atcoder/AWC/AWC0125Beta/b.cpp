#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 貪欲法

int main(void){
  ll n, m, d, k; cin >> n >> m >> d >> k;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  sort(rbegin(a), rend(a));
  int ans=0;
  for(int i=min(m, k); i<n; i++){
    if(a[i]>d*m) ans++;
  }
  cout << ans << endl;
  return 0; 
}