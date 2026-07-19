#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

pair<vector<int>, map<int, int>> cc(vector<int>& a){ //座標圧縮
  vector<int> p=a;
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  map<int, int> f;
  int l=p.size();
  for(int i=0; i<l; i++) f[p[i]]=i+1;
  vector<int> ans;
  for(auto& x:a) ans.push_back(f[x]);
  return {ans, f};
}

int main(void){
  int h, w, n; cin >> h >> w >> n;
  vector<int> a(n), b(n);
  for(int i=0; i<n; i++) cin >> a[i] >> b[i];
  auto [aa, da]=cc(a);
  auto [bb, db]=cc(b);
  for(int i=0; i<n; i++){
    cout << da[a[i]] << ' ' << db[b[i]] << endl;
  }
  return 0;
}