#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
void chmin(ll& a, ll b){a=min(a, b);}

//Tags: bitDP, 転倒数

int main(void){
  ll n, x, y; cin >> n >> x >> y;
  vector<ll> a(n), b(n);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  int mx=(1<<n);
  vector<ll> dp(mx, 1e18);
  dp[0]=0;
  for(int i=0; i<mx; i++){
    int k=__builtin_popcount(i);
    int n1=k;
    for(int j=0; j<n; j++){
      if(i>>j&1){n1--; continue;}
      //akと対応する位置に置くのがbj
      //前からk個1を置くのにn1個だけ1が左に行くため、元々jにあった要素はn1だけ右に行く
      //それを添字kの場所(前からk+1個目)に置くにはj+n1-k回だけ左に動かす必要がある。
      chmin(dp[i|(1<<j)], dp[i]+abs(a[k]-b[j])*x+y*abs(j+n1-k));
    }
  }
  cout << dp[mx-1] << endl;
  return 0; 
}