#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main(void){
  ll n, k, p; cin >> n >> k >> p;
  vector<ll> h(n);
  for(auto&x:h) cin >> x;
  sort(rbegin(h), rend(h));
  ll cnt=0;
  for(int i=0; i<n; i++){
    if(h[i]>0) continue;
    ll d=-h[i]+1;
    ll now=(d+p-1)/p;
    if(cnt+now<=k) cnt+=now, h[i]+=now*p;
    else break;
  }
  int ans=0;
  for(int i=0; i<n; i++) ans+=(h[i]<=0);
  cout << ans << endl;
  return 0; 
}