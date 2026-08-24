#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;

//Tags: 貪欲法

int main(void){
  ll n, h; cin >> n >> h;
  priority_queue<ll, vector<ll>, greater<ll>> pri;
  vector<ll> d(n);
  for(auto&x:d) cin >> x;
  int ans=0;
  pri.emplace(d[n-1]);
  for(int i=n-2; i>=0; i--){
    ll rem=h;
    while(rem&&pri.size()){
      auto p=pri.top(); pri.pop();
      ll d=min(p, rem);
      rem-=d, p-=d;
      if(p) pri.push(p);
      else ans++;
    }
    pri.push(d[i]);
  }
  cout << ans << endl;
  return 0; 
}