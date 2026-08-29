#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 貪欲法, 二分探索
//Level: 2

int f(vector<int> s, vector<int> t){
  multiset<int> stand;
  for(auto p:s) stand.insert(p);
  int m=t.size();
  for(int i=0; i<m; i++){
    auto p=stand.lower_bound(t[i]);
    if(p==stand.end()) return i;
    stand.erase(p);
  }
  return m;
}

int main(void){
  int n, m; cin >> n >> m;
  vector<int> s(n), t(m);
  multiset<int> stand;
  for(auto& p:s) cin >> p, stand.insert(p);
  for(auto& p:t) cin >> p;
  int maxi=f(s, t);
  if(maxi==0){
    cout << 0 << endl; return 0;
  }
  vector<int> tt;
  for(int i=0; i<maxi; i++){
    tt.push_back(t[i]);
  }
  sort(tt.rbegin(), tt.rend());
  int left=-1e9-5, right=1e9;
  while(right-left>1){
    int mid=(left+right)/2;
    multiset<int> S=stand;
    bool ok=true;
    for(auto p:tt){
      auto q=S.upper_bound(p+mid);
      if(q==S.begin()){ok=false; break;}
      auto r=prev(q);
      if((*r)>=p) S.erase(r);
      else{ok=false; break;}
    } 
    if(ok) right=mid;
    else left=mid;
  }
  cout << right << endl;
  return 0;
}
