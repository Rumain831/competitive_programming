#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: DFS

int main(void){
  int n; cin >> n;
  vector<vector<int>> to(n);
  for(int i=1; i<n; i++){
    int p; cin >> p; p--;
    to[p].push_back(i);
  }
  vector<ll> v(n);
  for(auto&x:v) cin >> x;
  auto dfs=[&](auto dfs, int now, int par=-1)->bool {
    ll ch=0;
    for(auto p:to[now])if(p!=par){
      if(!dfs(dfs, p, now)) return false;
      ch+=v[p];
    }
    if(ch>v[now]) return false;
    return true;
  };
  cout << (dfs(dfs, 0)?"Yes":"No") << endl;
  return 0; 
}