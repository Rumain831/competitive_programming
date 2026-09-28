#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: Simulation, 二分探索

int main(void){
  ll n, m, k; cin >> n >> m >> k;
  vector<ll> s(n), g(m), rem(m, k);
  for(auto&x:s) cin >> x;
  for(auto&x:g) cin >> x;
  sort(begin(g), end(g));
  int ans=0;
  for(auto p:s){
    int k=upper_bound(begin(g), end(g), p)-begin(g);
    if(k==0) continue;
    k--;
    if(rem[k]) ans++, rem[k]--;
  }
  cout << ans << endl;
  return 0; 
}