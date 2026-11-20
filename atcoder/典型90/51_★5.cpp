#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 半分全列挙
//解説URL: https://twitter.com/e869120/status/1398046858933538819

vector<vector<ll>> all(vector<ll>& a){
  vector<vector<ll>> ans(41);
  int n=a.size(), mx=(1<<n);
  for(int i=0; i<mx; i++){
    ll now=0, c=0;
    for(int j=0; j<n; j++)if(i>>j&1) now+=a[j], c++;
    ans[c].push_back(now);
  }
  for(int i=0; i<41; i++) sort(begin(ans[i]), end(ans[i]));
  return ans;
}

int main(void){
  ll n, k, p; cin >> n >> k >> p;
  vector<vector<ll>> price(2);
  for(int i=0; i<n; i++){
    ll a; cin >> a;
    if(i<n/2) price[0].push_back(a);
    else price[1].push_back(a);
  }
  auto pre=all(price[0]);
  auto aft=all(price[1]);
  ll ans=0;
  for(int i=0; i<=k; i++){
    for(auto q:pre[i]){
      ll x=upper_bound(begin(aft[k-i]), end(aft[k-i]), p-q)-begin(aft[k-i]);
      ans+=x;
    }
  }
  cout << ans << endl;
  return 0; 
}