#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;

//Tags: 貪欲法

int main(void){
  int n, m, k, q; cin >> n >> m >> k >> q;
  vector<vector<ll>> vec(m);
  for(int i=0; i<n; i++){
    ll v, c; cin >> v >> c; c--;
    vec[c].push_back(v);
  } 
  priority_queue<ll, vector<ll>, greater<ll>> pri;
  ll ans=0;
  for(int i=0; i<q; i++){
    int s; cin >> s; s--;
    for(auto x:vec[s]){
      ans+=x;
      pri.push(x);
    }
    while(pri.size()>k){
      ans-=pri.top(); pri.pop();
    }
  }
  cout << ans << endl;
  return 0; 
}