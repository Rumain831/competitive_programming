#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 数列

//Hint: aが最大になるところは、もうそれ以上高くする必要がない

int main(void){
  ll n, d; cin >> n >> d;
  vector<ll> a(n), c(n);
  for(auto&x:a) cin >> x;
  for(auto&x:c) cin >> x;
  priority_queue<P> pri;
  for(int i=0; i<n; i++) pri.emplace(a[i], i);
  vector<ll> tar(n, -1);
  while(pri.size()){
    auto [x, id]=pri.top(); pri.pop();
    if(tar[id]!=-1) continue;
    tar[id]=x;
    for(int dd=-1; dd<=1; dd++){
      if(dd==0) continue;
      int nid=id+dd;
      if(nid<0||nid>=n) continue;
      if(tar[nid]!=-1) continue;
      ll nx=max(0ll, x-d);
      if(a[nid]>=nx) continue;
      pri.emplace(nx, nid);
    }
  }
  ll ans=0;
  for(int i=0; i<n; i++) ans+=(tar[i]-a[i])*c[i];
  cout << ans << endl;
  return 0; 
}