#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 二分探索, 最大公約数
//Level: 2.5

int main(void){
  ll n, k; cin >> n >> k;
  vector<ll> a(n), b(n);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  vector<vector<P>> cnt(n);
  for(int i=0; i<n; i++){
    for(int j=1; j*j<=a[i]; j++){
      if(a[i]%j) continue;
      cnt[i].emplace_back(j, 0);
      if(j!=a[i]/j) cnt[i].emplace_back(a[i]/j, 0);
    }
    sort(begin(cnt[i]), end(cnt[i]));
    for(auto&[d, x]:cnt[i]){
      ll y=(b[i]+d-1)/d*d;
      x=y-b[i];
    }
    int m=cnt[i].size();
    for(int j=m-2; j>=0; j--) cnt[i][j].second=min(cnt[i][j].second, cnt[i][j+1].second);
  }
  auto judge=[&](ll x){
    ll ans=0;
    for(int i=0; i<n; i++){
      if(x>a[i]) return false;
      ll now=(*lower_bound(begin(cnt[i]), end(cnt[i]), P(x, 0))).second;
      ans+=now;
    }
    return ans<=k;
  };
  ll left=1, right=1e11;
  while(right-left>1){
    ll mid=(left+right)/2;
    if(judge(mid)) left=mid;
    else right=mid;
  }
  cout << left << endl;
  return 0; 
}