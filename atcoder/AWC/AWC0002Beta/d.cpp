#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(void){
  int n, m; cin >> n >> m;
  vector<int> c(n), r(m);
  set<int> p;
  for(auto&x:c) cin >> x, p.insert(x);
  for(auto&x:r) cin >> x;
  sort(c.begin(), c.end());
  sort(r.begin(), r.end());
  int ans=0;
  for(int i=0; i<m; i++){
    auto q=p.upper_bound(r[i]);
    if(q==p.begin()) continue;
    q--;
    ans++;
    p.erase(q);
  }
  cout << ans << endl;
  return 0;
}