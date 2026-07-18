#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using P = pair<int, int>;

//スライド最小値・最大値を用いる方法。
int main(void){
  int n, k; cin >> n >> k;
  vector<int> h(n);
  for(auto&x:h) cin >> x;
  auto adjust=[&](deque<P>& q, int now, int idx){
    while(q.size()){
      if(q.back().first<now) q.pop_back();
      else break;
    }
    q.emplace_back(now, idx);
  };
  deque<P> mi, mx;
  for(int i=0; i<k-1; i++){
    adjust(mi, -h[i], i);
    adjust(mx, h[i], i);
  }
  int ans=-2e9;
  for(int i=k-1; i<n; i++){
    adjust(mi, -h[i], i);
    adjust(mx, h[i], i);
    while(mi.size()&&mi.front().second<i-k+1) mi.pop_front();
    while(mx.size()&&mx.front().second<i-k+1) mx.pop_front();
    ans=max(ans, mx.front().first+mi.front().first);
  }
  cout << ans << endl;
  return 0;
}