#include<iostream>
#include<set>
using namespace std;
using ll = long long;

//Tags: 整数, 全探索
//Level: 1.5

int main(void){
  ll n; cin >> n;
  set<ll> sq;
  for(ll i=1; i<=n; i++) sq.insert(i*i);
  int ans=0;
  for(ll i=1; i<n; i++){
    ll rem=n*n-i*i;
    ans+=sq.count(rem);
  }
  cout << ans << endl;
  return 0; 
}