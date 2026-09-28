#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//Tags: 貪欲法

int main(void){
  int n, m; cin >> n >> m;
  multiset<int> s;
  vector<int> d(m);
  for(int i=0; i<n; i++){int x; cin >> x; s.insert(x);}
  for(auto&x:d) cin >> x;
  sort(rbegin(d), rend(d));
  int ans=0;
  for(int i=0; i<m; i++){
    auto it=s.lower_bound(d[i]);
    if(it==end(s)) continue;
    ans++, s.erase(it);
  }
  cout << ans << endl;
  return 0; 
}