#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main(void){
  ll n, k; cin >> n >> k;
  int ans=0;
  while(n--){
    ll x; cin >> x;
    ans+=(x<=k);
  }
  cout << ans << endl;
  return 0; 
}