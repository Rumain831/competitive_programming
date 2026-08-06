#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: 辞書順
//https://codeforces.com/contest/2254/problem/D
//全部0なら全要素1の数列が答え
//そうでないとき、bを降順に並べる
//例えば x x y y y z ... とあるときx-yを3要素で、y-zを1要素で賄うべき。 p=(x-y)/3, q=(y-z)/1として
//      ? ? p p p q ... となる。割り切れない箇所があれば-1。最後までいったら?をp+1でやれば答え。

void solve(){
  int n; cin >> n;
  vector<P> val;
  for(int i=0; i<n; i++){
    ll a; cin >> a;
    val.emplace_back(a, i);
  }
  sort(rbegin(val), rend(val));
  if(val.back().first!=0){
    cout << -1 << '\n'; return;
  }
  if(val[0].first==0){
    for(int i=0; i<n; i++) cout << 1 << (i==n-1?'\n':' ');
    return;
  }
  vector<ll> ans(n, -1);
  ll l=0, r=0, mx=-1, pre=1e18;
  {
    ll now=val[0].first;
    while(val[l].first==now) l++;
    r=l;
  }
  while(l<n){
    ll big=val[l-1].first, small=val[l].first;
    while(r<n&&val[r].first==small) r++;
    ll c=r-l, d=big-small;
    if(d%c||pre<=d/c){
      cout << -1 << '\n'; return;
    }
    pre=d/c;
    mx=max(mx, pre);
    for(int i=l; i<r; i++) ans[val[i].second]=d/c;
    l=r;
  }
  for(int i=0; i<n; i++)if(ans[i]==-1) ans[i]=mx+1;
  for(auto p:ans) cout << p << ' '; cout << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}