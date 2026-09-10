#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 全探索, 累積和, 幾何
//Level: 2

int main(void){
  int n; cin >> n;
  vector cnt(3, vector<ll>(3001));
  vector<ll> sum(3001);
  for(int i=0; i<3; i++){
    for(int j=0; j<n; j++){
      int x; cin >> x;
      cnt[i][x]++;
    }
  }
  for(int i=1; i<3001; i++) sum[i]+=sum[i-1]+cnt[2][i];
  ll ans=0;
  for(int i=1; i<3001; i++)if(cnt[0][i]){
    for(int j=1; j<=i; j++)if(cnt[1][j]){
      int l=max(1, i-j+1);
      ans+=(ll)cnt[0][i]*(cnt[1][j]*(sum[i]-sum[l-1]));
    }
  }
  cout << ans << endl;
  return 0; 
}