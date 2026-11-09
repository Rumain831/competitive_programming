#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 二分探索

int main(void){
  ll n, k, p; cin >> n >> k >> p;
  vector<P> pr;
  for(int i=0; i<n; i++){
    ll a, b; cin >> a >> b;
    pr.emplace_back(a, b);
  }
  auto judge=[&](ll x){
    vector<ll> ok;
    for(int i=0; i<n; i++){
      auto [a, b]=pr[i];
      if(b<=x) ok.push_back(a);
    }
    sort(rbegin(ok), rend(ok));
    ll now=0, m=ok.size();
    if(m<k) return false;
    for(int i=0; i<min(m, k); i++){
      now+=ok[i];
    }
    return now>=p;
  };
  ll left=0, right=1e18;
  if(!judge(right)){
    cout << -1 << endl; return 0;
  }
  while(right-left>1){
    ll mid=(left+right)/2;
    if(judge(mid)) right=mid;
    else left=mid;
  }
  cout << right << endl;
  return 0; 
}