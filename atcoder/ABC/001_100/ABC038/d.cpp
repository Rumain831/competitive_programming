#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: LIS

int main(void){
  int n; cin >> n;
  vector<pair<int, int>> box(n);
  vector<int> W, H, emp(n);
  for(auto&[w, h]:box) cin >> w >> h;
  sort(box.begin(), box.end(), [](const P& a, const P& b){
    auto [aw, ah]=a;
    auto [bw, bh]=b;
    if(aw!=bw) return aw<bw;
    else return ah>bh;
  });
  int mx=1e5+5;
  vector<int> dp(mx, 1e9);
  for(auto [_, h]:box){
    int k=lower_bound(begin(dp), end(dp), h)-begin(dp);
    dp[k]=h;
  }
  int ans=lower_bound(begin(dp), end(dp), 1e9)-begin(dp);
  cout << ans << endl;
  return 0;
}