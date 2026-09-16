#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 全探索

int main(void){
  ll m, d; cin >> m >> d;
  vector<ll> l(m+1), r(m+1), v(m+1);
  vector<P> L, R;
  for(int i=0; i<m; i++){
    cin >> l[i] >> r[i] >> v[i];
    L.emplace_back(l[i], i);
    R.emplace_back(r[i], i);
  }
  L.emplace_back(0, m);
  R.emplace_back(0, m);
  sort(begin(L), end(L));
  sort(begin(R), end(R));
  auto Cost=[&](ll nl, ll nr){
    nl=min(nl, 0ll);
    nr=max(0ll, nr);
    return nr-nl+min(abs(nl), abs(nr));
  };
  auto ok=[&](ll nl, ll nr, int id){
    nl=min(nl, 0ll);
    nr=max(0ll, nr);
    return (nl<=l[id])&&(r[id]<=nr);
  };
  ll ans=0;
  for(int i=0; i<=m; i++){
    auto [nl, _]=L[i];
    ll now=0;
    for(int j=0; j<=m; j++){
      auto [nr, ri]=R[j];
      ll cost=Cost(nl, nr);
      if(cost>d) break;
      if(ok(nl, nr, ri)) now+=v[ri];
      ans=max(ans, now);
    }
  }
  cout << ans << endl;
  return 0; 
}