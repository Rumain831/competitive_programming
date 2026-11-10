#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//Tags: 座標圧縮

pair<vector<int>, map<int, int>> cc(vector<int>& a){ //座標圧縮
  vector<int> p=a;
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  map<int, int> f;
  int l=p.size();
  for(int i=0; i<l; i++) f[p[i]]=i;
  vector<int> ans;
  for(auto& x:a) ans.push_back(f[x]);
  return {ans, f};
}

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  auto [b, f]=cc(a);
  for(auto p:b) cout << p << endl;
  return 0;
}
