#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

ll two(ll a){
  return a*a;
}

int main(void){
  ll xa, ya, xb, yb, t, v;
  cin >> xa >> ya >> xb >> yb >> t >> v;
  int n; cin >> n;
  vector<ll> p(n), q(n);
  for(int i=0; i<n; i++) cin >> p[i] >> q[i];
  for(int i=0; i<n; i++){
    ll x=p[i], y=q[i]; 
    if(4*((two(x-xa)+two(y-ya))*(two(x-xb)+two(y-yb)))<=
    two(two(t*v)-(two(x-xa)+two(y-ya)+two(x-xb)+two(y-yb)))){
      cout << "YES" << endl; return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}