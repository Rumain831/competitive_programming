#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

void solve(){
  int n; cin >> n;
  vector<ll> ab(n);
  ll mi=1e18, sum=0;
  for(int i=0; i<n; i++){
    ll a, b; cin >> a >> b;
    ab[i]=a-b, sum+=a;
    mi=min(mi, a);
  }
  sort(rbegin(ab), rend(ab));
  ll ans=sum, dif=0;
  for(int i=0; i<n; i++){
    dif+=ab[i];
    ll now=sum-dif;
    ll need=max(0, 2*(i+1)-n);
    now+=need*mi;
    ans=min(ans, now);
  }
  cout << ans << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}