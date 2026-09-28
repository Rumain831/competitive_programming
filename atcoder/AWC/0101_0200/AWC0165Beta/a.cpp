#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: Simulation

int main(void){
  int n, q; cin >> n >> q;
  vector<ll> a(n), b(n);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  while(q--){
    int c; cin >> c; c--;
    a[c]=max(a[c]-b[c], 0ll);
    ll d=a[c];
    a[c]=0;
    if(c+1<n) a[c+1]+=d;
  }
  for(auto p:a) cout << p << ' '; cout << endl;
  return 0; 
}