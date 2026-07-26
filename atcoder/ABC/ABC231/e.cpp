#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
void chmin(ll& a, ll b){a=min(a, b);}

//Tags: 桁dp, 繰り上がり

int main(void){
  ll n, x; cin >> n >> x;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  ll inf=1e18;
  ll dp[2]={inf, inf};
  dp[0]=0;
  for(int i=0; i<n; i++){
    ll old[2]={inf, inf};
    swap(old, dp);
    for(int p=0; p<2; p++)for(int q=0; q<2; q++){
      ll pay=x-x%a[i];
      if(i+1<n) pay%=a[i+1];
      pay+=p*a[i];
      if(q) pay=a[i+1]-pay;
      chmin(dp[q], old[p]+pay/a[i]);
    }
  }
  cout << dp[0] << endl;
  return 0; 
}