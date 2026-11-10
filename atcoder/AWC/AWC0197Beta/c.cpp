#include<iostream>
#include<map>
using namespace std;
using ll = long long;

//Tags: map

int main(void){
  int n; cin >> n;
  map<ll, ll> cnt;
  ll ans=0;
  for(int i=0; i<n; i++){
    ll a, b; cin >> a >> b;
    ans+=cnt[a-b];
    cnt[a-b]++;
  }
  cout << ans << endl;
  return 0; 
}