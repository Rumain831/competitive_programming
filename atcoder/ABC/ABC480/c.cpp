#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: Simulation

int main(void){
  ll n, k, t; cin >> n >> k >> t;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  sort(begin(a), end(a));
  int id=0, ans=0;
  ll must=0;
  while(id<n){
    if(must>=t) break;
    auto nt=a[id];
    if(nt<=must){
      must=max(must, nt+k), id++;
      continue;
    }
    ll dt=min(nt, t)-must, cnt=(dt+k-1)/k;
    ans+=cnt, must+=cnt*k;
  }
  if(must<t){
    ll cnt=(t-must+k-1)/k; ans+=cnt;
  } 
  cout << ans << endl;
  return 0; 
}