#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: 二分探索

int main(void){
  int n, q; cin >> n >> q;
  vector<ll> p(n), d(n), mx(n, -1);
  for(int i=0; i<n; i++) cin >> p[i] >> d[i];
  ll sum=0, pre=1e18;
  for(int i=0; i<n; i++){
    ll x=p[i]-sum;
    if(x<0) break;
    mx[i]=min(pre, x);
    pre=mx[i];
    sum+=d[i];
  }
  reverse(begin(mx), end(mx));
  while(q--){
    int s; cin >> s;
    int ans=end(mx)-lower_bound(begin(mx), end(mx), s);
    cout << ans << '\n';
  }
  return 0; 
}