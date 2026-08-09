#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: 半分全列挙

map<ll, vector<vector<int>>> Enum(vector<P>& a){
  int n=a.size();
  int mx=(1<<n);
  map<ll, vector<vector<int>>> ans;
  for(int i=0; i<mx; i++){
    vector<int> buy;
    ll sum=0;
    for(int j=0; j<n; j++)if(i>>j&1){
      auto [p, id]=a[j];
      sum+=p;
      buy.push_back(id);
    }
    ans[sum].push_back(buy);
  }
  return ans;
}

int main(void){
  int n; ll s; cin >> n >> s;
  vector<P> pre, aft;
  for(int i=0; i<n; i++){
    ll p; cin >> p;
    if(i<max(1, n/2)) pre.emplace_back(p, i+1);
    else aft.emplace_back(p, i+1);
  } 
  auto a1=Enum(pre);
  auto a2=Enum(aft);
  vector<vector<int>> ans;
  for(auto& [x, p]:a1){
    if(a2.count(s-x)==0) continue;
    for(auto p1:p)for(auto& p2:a2[s-x]){
      vector<int> now=p1;
      for(auto x:p2) now.push_back(x);
      ans.push_back(now); 
    }
  }
  sort(begin(ans), end(ans));
  for(auto p:ans){
    for(auto q:p) cout << q << ' '; cout << endl;
  }
  return 0; 
}