#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 二分探索, ワーシャルフロイド法
//解説URL: https://twitter.com/e869120/status/1413266660862009348

int main(void){
  ll n, p, k; cin >> n >> p >> k;
  vector a(n, vector<ll>(n));
  for(auto&x:a)for(auto&y:x) cin >> y;
  auto cnt=[&](ll x){
    vector<vector<ll>> dist=a;
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)if(dist[i][j]==-1) dist[i][j]=x;
    for(int k=0; k<n; k++)for(int i=0; i<n; i++)for(int j=0; j<n; j++){
      dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
    }
    int ans=0;
    for(int i=0; i<n-1; i++)for(int j=i+1; j<n; j++){
      ans+=(dist[i][j]<=p);
    }
    return ans;
  };

  {
    ll x=cnt(1e18), y=cnt(1);
    if(x==k){
      cout << "Infinity" << endl; return 0;
    }
    else if(x>k||y<k){
      cout << 0 << endl; return 0;
    }
  }

  auto solve=[&](ll x)->ll {
    ll lim=cnt(1e18), one=cnt(1);
    if(lim>x) return 1e18;
    if(one<=x) return 1ll;
    ll left=1, right=1e18;
    while(right-left>1){
      ll mid=(left+right)/2;
      ll now=cnt(mid);
      if(now<=x) right=mid;
      else left=mid;
    }
    return right;
  };
  
  ll x=solve(k), y=solve(k-1);
  cout << y-x << endl;
  return 0;
}