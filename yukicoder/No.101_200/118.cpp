#include<iostream>
#include<map>
using namespace std;
using ll = long long;

//Tags: 数え上げ

int main(void){
  int n; cin >> n;
  map<int, ll> cnt;
  ll l=0, r=n, ans=0, mod=1e9+7;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    cnt[a]++;
  }
  for(auto [_, x]:cnt){
    r-=x;
    ans+=l*r*x%mod, ans%=mod;
    l+=x;
  }
  cout << ans << endl;
  return 0; 
}