#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using ll = long long;
using tu = tuple<int, int, int>;

//Tags: 数え上げ

int main(void){
  int n; cin >> n;
  vector<tu> mount;
  vector<vector<int>> col(n);
  for(int i=0; i<n; i++){
    int c, h; cin >> c >> h; c--;
    mount.emplace_back(h, c, i);
    col[c].push_back(i);
  }
  sort(rbegin(mount), rend(mount));
  set<int> used={-1, (int)1e9};
  ll ans=0;
  for(int i=0; i<n; i++){
    auto [h, c, pos]=mount[i];
    auto it=used.upper_bound(pos);
    auto it2=prev(it);
    int r=*it, l=*it2;
    int x=lower_bound(begin(col[c]), end(col[c]), r)-upper_bound(begin(col[c]), end(col[c]), l);
    ans+=x-1;
    used.insert(pos);
  }
  cout << ans << endl;
  return 0; 
}