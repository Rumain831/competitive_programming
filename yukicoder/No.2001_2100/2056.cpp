#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: Simulation

int main(void){
  ll n, x, m; cin >> n >> x >> m;
  vector<ll> a(n);
  for(auto&y:a) cin >> y;
  int c=0;
  ll cost=0;
  for(int t=n; t>=1; t--){
    int i=t-1, now=0;
    while(a[i]>=x){
      now++, a[i]/=2;
    }
    ll add=max(0, now-c);
    cost+=add*t;
    c=max(c, now);
  }
  cout << (cost<=m?"Yes":"No") << endl;
  return 0; 
}