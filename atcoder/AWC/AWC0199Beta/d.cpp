#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 尺取り法

pair<vector<int>, map<ll, int>> cc(vector<ll>& a){ //座標圧縮
  vector<ll> p=a;
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  map<ll, int> f;
  int l=p.size();
  for(int i=0; i<l; i++) f[p[i]]=i;
  vector<int> ans;
  for(auto& x:a) ans.push_back(f[x]);
  return {ans, f};
}

int main(void){
  int n, w, h; cin >> n >> w >> h;
  vector<P> fish(n);
  vector<ll> ys;
  for(auto&[x, y]:fish) cin >> x >> y;
  sort(begin(fish), end(fish));
  for(auto [_, y]:fish) ys.push_back(y);
  auto [yc, dict]=cc(ys);
  int ans=0, rw=-1, m=dict.size();
  vector<ll> inv(m);
  for(auto [y, id]:dict) inv[id]=y;
  vector<int> cnt(m);
  for(int i=0; i<n; i++){
    if(rw<i) rw=0;
    auto [nx, _]=fish[i];
    while(rw<n){
      auto [x, y]=fish[rw];
      if(nx+w<x) break;
      cnt[yc[rw]]++;
      rw++;
    }
    int hi=0, now=0;
    for(int j=0; j<m; j++){
      ll ny=inv[j];
      while(hi<m){
        ll y=inv[hi];
        if(ny+h<y) break;
        now+=cnt[hi];
        ans=max(ans, now);
        hi++;
      }
      now-=cnt[j];
    }
    cnt[yc[i]]--;
  }
  cout << ans << endl;
  return 0; 
}