#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;

//Tags: Simulation
//Level: 1.5

int main(void){
  ll n, k, x; cin >> n >> k >> x;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  priority_queue<ll, vector<ll>, greater<ll>> pri;
  ll now=0, ans=-1e18;
  for(int i=0; i<n; i++){
    now+=a[i]; pri.push(a[i]);
    if(pri.size()>k) now-=pri.top(), pri.pop();
    ans=max(ans, now-x*(i+1));
  }
  cout << ans << endl;
  return 0; 
}