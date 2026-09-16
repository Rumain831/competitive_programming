#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: 四則演算

int main(void){
  ll n, v, q; cin >> n >> v >> q;
  vector<ll> t(n), w(n);
  for(int i=0; i<n; i++) cin >> t[i] >> w[i];
  vector<P> query;
  vector<ll> ans(q);
  for(int i=0; i<q; i++){
    ll x; cin >> x;
    query.emplace_back(x, i);
  }
  sort(begin(query), end(query));
  ll pos=0, pt=0, qi=0, vel=0;
  for(int i=0; i<n; i++){
    ll nt=t[i];
    ll sp=(vel==0?0:abs(vel)+v);
    while(qi<q){
      auto [x, id]=query[qi];
      if(x>nt) break;
      ll res=pos+(x-pt)*sp*(vel<0?-1:1);
      ans[id]=res;
      qi++;
    }
    pos+=(nt-pt)*sp*(vel<0?-1:1);
    pt=nt, vel=w[i];
  }
  while(qi<q){
    auto [x, id]=query[qi];
    ll sp=(vel==0?0:abs(vel)+v);
    ll res=pos+(x-pt)*sp*(vel<0?-1:1);
    ans[id]=res;
    qi++;
  }
  for(auto p:ans) cout << p << '\n';
  return 0; 
}