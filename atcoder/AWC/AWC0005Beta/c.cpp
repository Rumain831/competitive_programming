#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Aiが大きなものからBiが決定されていくイメージ
int main(void){
  int n, k; cin >> n >> k;
  vector<ll> a(n), b(n);
  for(auto&x:a) cin >> x;
  b=a;
  priority_queue<P> pri;
  for(int i=0; i<n; i++) pri.push(P(a[i], i));
  vector<bool> seen(n);
  ll ans=0;
  while(pri.size()){
    auto [cnt, idx]=pri.top(); pri.pop();
    if(seen[idx]) continue;
    seen[idx]=true;
    a[idx]=cnt;
    for(int d=-1; d<=1; d++)if(d!=0){
      int ni=idx+d;
      if(ni<0||ni>=n) continue;
      if(seen[ni]) continue;
      if(abs(cnt-a[ni])>k){
        a[ni]=cnt-k;
        pri.emplace(a[ni], ni);
      }
    }
  }
  for(int i=0; i<n; i++) ans+=a[i]-b[i];
  cout << ans << endl;
  return 0;
}