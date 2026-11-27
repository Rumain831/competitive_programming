#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 木dp

int main(void){
  int n; cin >> n;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  vector<vector<int>> to(n);
  for(int i=0; i<n-1; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v); swap(u, v);
    to[u].push_back(v);
  }
  //救護所あり, 子孫に1箇所, 子孫に2箇所以上
  vector dp(n, vector<ll>(3, 1e18));
  auto dfs=[&](auto dfs, int now, int par=-1)->void {
    bool leaf=true;
    ll minsum=0, min0=1e18, c=0, sum0=0;
    vector<ll> cost02;
    for(auto p:to[now])if(p!=par){
      dfs(dfs, p, now);
      leaf=false, c++;
      minsum+=min({dp[p][0], dp[p][1], dp[p][2]});
      min0=min(min0, dp[p][0]);
      sum0+=dp[p][0];
      cost02.emplace_back(dp[p][2]-dp[p][0]);
    }
    if(leaf){
      dp[now][0]=a[now];
    }
    else{
      dp[now][0]=a[now]+minsum;
      sort(begin(cost02), end(cost02));
      if(c>=1){
        ll nows=sum0;
        for(int i=0; i<c-1; i++){
          if(cost02[i]>=0) break;
          nows+=cost02[i];
        }
        dp[now][1]=min(dp[now][1], nows);
      }
      if(c>=2){
        ll nows=sum0;
        for(int i=0; i<c-2; i++){
          if(cost02[i]>=0) break;
          nows+=cost02[i];
        }
        dp[now][2]=min(dp[now][2], nows);
      }
    }
  };
  dfs(dfs, 0);
  cout << min(dp[0][0], dp[0][2]) << endl;
  return 0; 
}