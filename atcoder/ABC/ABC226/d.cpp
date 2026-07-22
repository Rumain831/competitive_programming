#include<iostream>
#include<vector>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 整数, gcd

ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}

int main(void){
  int n; cin >> n;
  vector<ll> x(n), y(n);
  for(int i=0; i<n; i++) cin >> x[i] >> y[i];
  set<P> all;
  for(int i=0; i<n-1; i++)for(int j=i+1; j<n; j++){
    ll d=gcd(abs(x[i]-x[j]), abs(y[i]-y[j]));
    ll dx=(x[i]-x[j])/d, dy=(y[i]-y[j])/d;
    all.insert(P(dx, dy));
    all.insert(P(-dx, -dy));
  }
  cout << all.size() << endl;
  return 0;
}