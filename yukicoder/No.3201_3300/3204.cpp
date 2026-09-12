#include<iostream>
#include<vector>
#include<array>
#include<map>
using namespace std;
using ll = long long;
using ar = array<int, 10>;

//Tags: 整数, 平方数
//Level: 2

ar f(ll n){
  ar ans={};
  while(n){
    ans[n%10]++;
    n/=10;
  }
  return ans;
}

int main(void){
  map<ar, ll> mi;
  for(ll i=1; i*i<=1e10; i++){
    ar now=f(i*i);
    if(mi.count(now)==0) mi[now]=i*i;
  }
  int t; cin >> t;
  while(t--){
    ll n; cin >> n;
    ar now=f(n);
    ll ans=1e18;
    while(now[0]>=0){
      if(mi.count(now)) ans=min(ans, mi[now]);
      now[0]--;
    }
    cout << (ans==1e18?-1:ans) << '\n';
  }
  return 0; 
}