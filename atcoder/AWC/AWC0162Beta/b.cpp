#include<iostream>
#include<map>
using namespace std;
using ll = long long;

//Tags: 最適化

int main(void){
  ll n, x; cin >> n >> x;
  map<int, ll> p;
  for(int i=0; i<n; i++){
    int a; ll b; cin >> a >> b;
    if(a<x) p[a]=max(p[a], b);
  }
  ll ans=0;
  for(auto x:p) ans+=x.second;
  cout << ans << endl;
  return 0; 
}