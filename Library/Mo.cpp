#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
using ll = long long;
struct Query{
  int l, r, idx;
  Query(int l=0, int r=0, int idx=0):l(l), r(r), idx(idx){}
};
//ABC242G

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x, x--;
  int q; cin >> q;
  vector<Query> query;
  for(int i=0; i<q; i++){
    int l, r; cin >> l >> r;
    query.emplace_back(l-1, r, i);
  }
  int sq=max(1, (int)sqrt(n));
  vector<ll> cnt(n), ans(q);
  sort(query.begin(), query.end(), [&](auto& x, auto& y){
    int bx=x.l/sq, by=y.l/sq;
    if(bx!=by) return bx<by;
    else return ((bx&1)?x.r>y.r:x.r<y.r);
  });
  int l=0, r=0;
  ll now=0;
  auto add=[&](int i){
    now-=cnt[a[i]]/2;
    cnt[a[i]]++;
    now+=cnt[a[i]]/2;
  };
  auto erase=[&](int i){
    now-=cnt[a[i]]/2;
    cnt[a[i]]--;
    now+=cnt[a[i]]/2;
  };
  for(auto&qu:query){
    //半開区間用
    while(qu.l<l) add(--l);
    while(r<qu.r) add(r++);
    while(l<qu.l) erase(l++);
    while(qu.r<r) erase(--r);
    ans[qu.idx]=now;
    cout << qu.l << ' ' << qu.r << " : ";
    for(int i=0; i<3; i++) cout << cnt[a[i]] << ' '; cout << endl;
  }
  for(auto p:ans) cout << p << '\n';
  return 0; 
}