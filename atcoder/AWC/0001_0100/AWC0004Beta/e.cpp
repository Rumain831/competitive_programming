#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;

int main(void){
  int n, k; cin >> n >> k;
  vector<ll> a(n), sum={0};
  for(auto&x:a) cin >> x, sum.push_back(sum.back()+x);
  map<ll, ll> cnt;
  for(int i=0; i<=n; i++) cnt[sum[i]]++;
  ll ans=0;
  for(int i=0; i<n; i++){
    cnt[sum[i]]--;
    if(cnt.count(sum[i]+k)) ans+=cnt[sum[i]+k];
  }
  cout << ans << endl;
  return 0;
}