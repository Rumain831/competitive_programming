#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 平方分割

int main(void){
  int n; cin >> n;
  vector<ll> a(n), b(n);
  ll suma=0;
  for(int i=0; i<n; i++) cin >> a[i] >> b[i], suma+=a[i];
  ll B=700, m=5e5+1;
  vector<ll> big(m+1);
  vector<vector<ll>> small(B);
  for(int i=0; i<B; i++){
    for(int j=0; j<i+1; j++) small[i].push_back(0);
  }
  vector<vector<P>> add(m+1);
  for(int i=0; i<n; i++){
    ll x=b[i];
    if(x>=B){
      int st=b[i]-a[i];
      while(st<m){
        big[st]+=b[i];
        st+=b[i];
      }
    }
    else{
      int d=b[i]-a[i];
      add[d].emplace_back(d%b[i], b[i]);
    }
  }
  for(int i=1; i<=m; i++) big[i]+=big[i-1];
  int q; cin >> q;
  vector<P> query;
  for(int i=0; i<q; i++){
    ll x; cin >> x;
    query.emplace_back(x, i);
  }
  sort(begin(query), end(query));
  vector<ll> ans(q);
  int iq=0;
  ll y=0;
  for(int i=0; i<=m; i++){
    for(auto [r, bx]:add[i]){
      small[bx][r]+=bx;
    }
    for(int j=1; j<B; j++){
      y+=small[j][i%j];
    }
    while(iq<q){
      auto [x, id]=query[iq];
      if(x!=i) break;
      ll now=(ll)n*x+suma;
      ll minus=big[i];
      minus+=y;
      ans[id]=now-minus;
      iq++;
    }
  }
  for(auto p:ans) cout << p << '\n';
  return 0; 
}