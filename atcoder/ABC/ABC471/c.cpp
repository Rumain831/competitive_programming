#include<iostream>
#include<set>
using namespace std;
using ll = long long;

//Tags: Simulation

int main(void){
  ll n; cin >> n;
  set<ll> co;
  for(int i=0; i<n; i++){
    ll a; cin >> a;
    co.insert(a);
  }
  co.insert(-1e18);
  co.insert(1e18);
  ll ans=0, now=0;
  for(int i=0; i<n; i++){
    auto it1=co.upper_bound(now);
    auto it2=prev(it1); 
    ll d2=abs(now-*it2), d1=abs(now-*it1);
    ans+=min(d2, d1);
    if(d2<=d1){
      now=*it2, co.erase(it2);
    }
    else{
      now=*it1, co.erase(it1);
    }
  }
  cout << ans << endl;
  return 0; 
}