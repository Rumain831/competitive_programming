#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
using ll = long long;
using qu = tuple<int, int, int, int>;
void chmax(int& a, int b){a=max(a, b);}

//Tags: dp, grid

int main(void){
  int h, w, n; cin >> h >> w >> n;
  vector<qu> point;
  vector<int> ansh(h, -1), answ(w, -1), ans(n);
  for(int i=0; i<n; i++){
    int r, c, a; cin >> r >> c >> a; r--, c--;
    point.emplace_back(a, r, c, i);
  }
  sort(rbegin(point), rend(point));
  int id=0;
  while(id<n){
    int now=get<0>(point[id]);
    vector<qu> update;
    while(id<n){
      auto [val, r, c, ei]=point[id];
      if(val!=now) break;
      ans[ei]=max(ansh[r], answ[c])+1;
      update.emplace_back(val, r, c, ans[ei]);
      id++;
    }
    for(auto [_, r, c, x]:update){
      chmax(ansh[r], x);
      chmax(answ[c], x);
    }
  }
  for(auto p:ans) cout << p << '\n';
  return 0; 
}