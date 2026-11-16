#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 最適化, 中央値

int main(void){
  int n; cin >> n;
  vector<P> pos;
  ll sp=0;
  for(int i=0; i<n; i++){
    ll x, p; cin >> x >> p;
    pos.emplace_back(x, p);
    sp+=p;
  }
  sort(begin(pos), end(pos));
  ll tar=(sp+1)/2, tx=0, now=0;
  for(int i=0; i<n; i++){
    auto [x, p]=pos[i];
    if(now+p>=tar){
      tx=x; break;
    }
    now+=p;
  }
  ll ans=0;
  for(int i=0; i<n; i++){
    auto [x, p]=pos[i];
    ans+=p*abs(x-tx);
  }
  cout << ans << endl;
  return 0; 
}