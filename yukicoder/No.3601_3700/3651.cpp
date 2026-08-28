#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
ll mod = 100003;

//Tags: 約数, 周期性, ダブリング
//Level: 2.5

int main(void){
  ll n, k; cin >> n >> k;
  if(k==1){
    cout << n << endl; return 0;
  }
  vector<ll> sum(mod+1);
  for(int i=1; i<=mod; i++){
    int now=i;
    while(now<=mod){
      sum[now]+=i, sum[now]%=mod;
      now+=i;
    }
  }
  ll x=0;
  for(int i=1; i<=n; i++)if(n%i==0) x+=i, x%=mod;
  k-=2;
  vector db(60, vector<int>(mod+1));
  for(int i=1; i<=mod; i++) db[0][i]=sum[i];
  for(int i=1; i<60; i++){
    for(int j=1; j<=mod; j++) db[i][j]=db[i-1][db[i-1][j]];
  }
  int c=0;
  while(k){
    if(k&1) x=db[c][x];
    c++, k/=2;
  }
  cout << x << endl;
  return 0; 
}