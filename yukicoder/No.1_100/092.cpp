#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: dp, グラフ

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<vector<P>> to(n+1);
  for(int i=0; i<m; i++){
    int a, b, c; cin >> a >> b >> c; a--, b--;
    to[a].emplace_back(b, c); swap(a, b);
    to[a].emplace_back(b, c);
  }
  for(int i=0; i<n; i++) to[n].emplace_back(i, 0);
  k++;
  vector<int> d(k);
  for(int i=1; i<k; i++) cin >> d[i];
  vector<bool> dp(n+1);
  dp[n]=true;
  for(int i=0; i<k; i++){
    vector<bool> old(n);
    swap(old, dp);
    for(int j=0; j<=n; j++)if(old[j]){
      for(auto [v, c]:to[j])if(d[i]==c){
        dp[v]=true;
      }
    }
  }
  vector<int> ans;
  for(int i=0; i<n; i++)if(dp[i]) ans.push_back(i+1);
  cout << ans.size() << endl;
  for(auto p:ans) cout << p << ' '; cout << endl;
  return 0; 
}