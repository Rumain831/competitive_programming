#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 木, 主客転倒
//解説URL: https://twitter.com/e869120/status/1392974101061378049

int main(void){
  int n; cin >> n;
  vector<vector<int>> to(n);
  for(int i=0; i<n-1; i++){
    int a, b; cin >> a >> b; a--, b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  ll ans=0;
  vector<ll> sub(n);
  auto dfs=[&](auto dfs, int now, int par=-1)->void {
    sub[now]++;
    for(auto p:to[now])if(p!=par){
      dfs(dfs, p, now);
      sub[now]+=sub[p];
      ans+=sub[p]*(n-sub[p]);
    }
  };
  dfs(dfs, 0);
  cout << ans << endl;
  return 0;
}