#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: bitDP
//解説URL: https://twitter.com/e869120/status/1395510657634619394

ll sq(ll a, ll b){return a*a+b*b;}
void chmin(ll& a, ll b){a=min(a, b);}

int main(void){
  int n, k; cin >> n >> k;
  vector<ll> x(n), y(n);
  for(int i=0; i<n; i++) cin >> x[i] >> y[i];
  int mx=(1<<n);
  vector<ll> dist(mx);
  for(int i=1; i<mx; i++){
    vector<int> id;
    for(int j=0; j<n; j++)if(i>>j&1) id.push_back(j);
    int m=id.size();
    for(int p=0; p<m; p++)for(int q=p; q<m; q++){
      dist[i]=max(dist[i], sq(x[id[p]]-x[id[q]], y[id[p]]-y[id[q]]));
    }
  }
  vector dp(mx, vector<ll>(k+1, 9e18));
  for(int i=0; i<mx; i++) dp[i][1]=dist[i];
  for(int i=1; i<k; i++)for(int j=0; j<mx; j++){
    int rem=((mx-1)^j);
    for(int x=rem; x>0; x=(x-1)&rem){
      chmin(dp[j|x][i+1], max(dp[j][i], dist[x]));
    }
  }
  cout << dp[mx-1][k] << endl;
  return 0; 
}