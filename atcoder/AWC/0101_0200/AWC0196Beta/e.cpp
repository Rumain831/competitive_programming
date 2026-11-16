#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp, XOR

int n, mx=(1<<21);
vector<ll> cnt(vector<int> a){
  vector<ll> dp(mx+1);
  dp[0]=1;
  for(int i=0; i<n; i++){
    vector<ll> old(mx+1);
    swap(old, dp);
    for(int j=0; j<=mx; j++)if(old[j]){
      dp[j]+=old[j];
      dp[j^a[i]]+=old[j];
    }
  }
  return dp;
}

int main(void){
  int s;
  cin >> n >> s;
  vector<int> a(n), b(n);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  ll ans=0;
  auto cnta=cnt(a);
  auto cntb=cnt(b);
  for(int i=0; i<=s; i++) ans+=cnta[i]*cntb[s-i];
  cout << ans << endl;
  return 0; 
}