#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: 実装

int main(void){
  int n, m; cin >> n >> m;
  vector<int> p(m);
  for(auto&x:p) cin >> x;
  vector<P> po;
  for(int i=0; i<n; i++){
    string s; cin >> s;
    int sum=0;
    for(int j=0; j<m; j++)if(s[j]=='o') sum+=p[j];
    po.emplace_back(sum, i);
  }
  sort(rbegin(po), rend(po));
  vector<int> ans(n);
  int id=0, c=0;
  while(id<n){
    int now=po[id].first, d=0;
    while(id<n&&po[id].first==now){
      ans[po[id].second]=c+1;
      d++, id++;
    }
    c+=d;
  }
  for(auto p:ans) cout << p << '\n';
  return 0; 
}