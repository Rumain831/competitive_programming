#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void chmax(int& a, int b){a=max(a, b);}

//Tags: dp

int main(void){
  int n, k; cin >> n >> k;
  vector<ll> pos;
  vector<P> res;
  for(int i=0; i<n; i++){
    ll x, r; cin >> x >> r;
    res.emplace_back(x-r, x+r);
    pos.push_back(x-r);
    pos.push_back(x+r);
  }
  pos.emplace_back(-1e18);
  sort(begin(res), end(res));
  sort(begin(pos), end(pos));
  pos.erase(unique(begin(pos), end(pos)), end(pos));
  int m=pos.size();
  vector dp(m, vector<int>(k+1, -1e9));
  dp[0][0]=0;
  for(int i=1; i<m; i++)for(int j=1; j<=min(i, k); j++){
    vector<ll> ls;
    for(int x=0; x<n; x++){
      auto [L, R]=res[x];
      if(L<=pos[i]&&pos[i]<=R){
        ls.push_back(L);
      }
    }
    sort(begin(ls), end(ls));
    int l=ls.size(), id=0;
    for(int pre=0; pre<i; pre++)if(dp[pre][j-1]>=0){
      ll x=pos[pre];
      while(id<l){
        if(ls[id]<=x) id++;
        else break;
      }
      chmax(dp[i][j], dp[pre][j-1]+l-id);
    }
  }
  int ans=-1;
  for(int i=0; i<m; i++)for(int j=0; j<=k; j++) chmax(ans, dp[i][j]);
  cout << ans << endl;
  return 0; 
}