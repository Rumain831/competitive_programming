#include<iostream>
using namespace std;
using ll = long long;
const ll mod=1e9;

//Tags: 整数, 一次合同式
//Level: 3

ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}

ll extgcd(ll a, ll b, ll& x, ll& y){
  if(b==0){
    x=1, y=0; return a;
  }
  ll x1, y1;
  ll gcd=extgcd(b, a%b, x1, y1);
  x=y1; y=x1-(a/b)*y1;
  return gcd;
}

void solve(){
  ll n, m; cin >> n >> m;
  ll g=gcd(n, mod);
  if(m%g){
    cout << -1 << '\n'; return;
  }
  n/=g, m/=g; 
  ll p=mod/g;
  n%=p, m%=p;
  ll x, y;
  extgcd(n, p, x, y);
  ll ans=-m*x%p; ans=(ans+p)%p;
  if(ans==0) ans=p;
  cout << ans << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}