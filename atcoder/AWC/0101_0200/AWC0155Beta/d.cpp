#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 累積和, 全探索

int main(void){
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  vector mx(2, vector<ll>(n+2));
  for(int t=0; t<2; t++){
    ll now=0;
    for(int i=0; i<k-1; i++) now+=a[i];
    for(int i=k-1; i<n; i++){
      now+=a[i];
      mx[t][i+1]=max(mx[t][i], now);
      now-=a[i-k+1];
    }
    reverse(begin(a), end(a));
  }
  reverse(begin(mx[1]), end(mx[1]));
  ll ans=0;
  for(int i=k-1; i<n-1; i++){
    int r=i+2;
    if(r+k-1>=n) break;
    ans=max(ans, mx[0][i+1]+mx[1][i+3]);
  }
  cout << ans << endl;
  return 0; 
}