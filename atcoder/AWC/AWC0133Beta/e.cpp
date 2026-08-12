#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: スライド最大値

int main(void){
  int n, m, k, t; cin >> n >> m >> k >> t;
  int ans=0;
  auto push=[&](deque<P>& tar, ll x, int id){
    while(tar.size()){
      P now=tar.back();
      if(now.first<=x) tar.pop_back();
      else break;
    }
    tar.emplace_back(x, id);
  };
  while(n--){
    deque<P> mx, mi;
    vector<ll> s(m);
    for(auto&x:s) cin >> x;
    for(int i=0; i<k-1; i++){
      push(mx, s[i], i);
      push(mi, -s[i], i);
    }
    int dif=-1e9;
    for(int i=k-1; i<m; i++){
      push(mx, s[i], i);
      push(mi, -s[i], i);
      while(1){
        auto now=mx.front();
        if(now.second>=i-k+1) break;
        mx.pop_front();
      }
      while(1){
        auto now=mi.front();
        if(now.second>=i-k+1) break;
        mi.pop_front();
      }
      int now=mx.front().first+mi.front().first;
      dif=max(dif, now);
    }
    ans+=(dif>=t);
  }
  cout << ans << endl;
  return 0; 
}