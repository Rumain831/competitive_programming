#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 尺取り法

int main(void){
  ll n, k; cin >> n >> k;
  vector<ll> s(n);
  for(auto&x:s) cin >> x;
  ll ans=0, r=-1, now=1;
  for(int i=0; i<n; i++){
    if(s[i]==0){
      cout << n << endl; return 0;
    }
    if(r<i) r=i, now=1;
    while(r<n&&now*s[r]<=k) now*=s[r++];
    ans=max(ans, r-i);
    now/=s[i];
  }
  cout << ans << endl;
  return 0; 
}