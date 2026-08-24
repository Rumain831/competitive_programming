#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: Eulerのphi関数, 完全グラフ
//Level: 3

vector<ll> EulerPhi(int n){
  vector<ll> ans(n+1);
  vector<ll> prime;
  ans[1]=1;
  for(int i=2; i<=n; i++){
    if(ans[i]==0){
      prime.push_back(i);
      ans[i]=i-1;
    }
    for(auto p:prime){
      if((ll)i*p>n) break;
      ans[i*p]=ans[i]*(p-(i%p?1:0));
      if(i%p==0) break;
    }
  }
  return ans;
}

int main(void){
  vector<ll> phi=EulerPhi(1e7+1), sum=phi;
  sum[1]=0;
  for(int i=2; i<=1e7; i++) sum[i]+=sum[i-1];
  int t; cin >> t;
  while(t--){
    ll n; cin >> n;
    ll dis=sum[n], non=n*(n-1)/2-dis;
    ll ans=dis+non*2;
    cout << ans << '\n';
  }
  return 0; 
}