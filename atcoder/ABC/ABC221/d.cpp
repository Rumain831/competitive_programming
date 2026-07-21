#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: イベントソート

int main(void){
  int n; cin >> n;
  vector<ll> a(n), b(n);
  vector<P> event;
  for(int i=0; i<n; i++){
    cin >> a[i] >> b[i];
    event.emplace_back(a[i], 1);
    event.emplace_back(a[i]+b[i], -1);
  }
  sort(event.begin(), event.end());
  vector<ll> ans(n+1);
  int idx=0, cnt=0;
  ll pre=event[0].first, st;
  while(idx<2*n){
    st=event[idx].first;
    ans[cnt]+=st-pre;
    while(idx<2*n&&event[idx].first==st){
      cnt+=event[idx].second;
      idx++;
    }
    pre=st;
  }
  for(int i=1; i<=n; i++) cout << ans[i] << ' '; cout << endl;
  return 0;
}