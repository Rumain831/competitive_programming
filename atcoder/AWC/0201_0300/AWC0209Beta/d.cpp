#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp

int main(void){
  int n, k; cin >> n >> k;
  vector<int> a(n), b(n);
  for(int i=0; i<n; i++) cin >> a[i] >> b[i];
  vector dp(k+1, vector<ll>(2));
  dp[0][0]=dp[0][1]=1;
  ll mod=998244353;
  for(int i=1; i<n; i++){
    vector old(k+1, vector<ll>(2));
    swap(old, dp);
    for(int j=0; j<=k; j++){
      for(int p=0; p<2; p++)for(int q=0; q<2; q++){
        int x=(p?a[i-1]:b[i-1]);
        int y=(q?a[i]:b[i]);
        int nj=j+(x==y);
        if(nj<=k) dp[nj][q]+=old[j][p], dp[nj][q]%=mod;
      }
    }
  }
  cout << (dp[k][0]+dp[k][1])%mod << endl;
  return 0; 
}