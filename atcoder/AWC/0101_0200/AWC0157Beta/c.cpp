#include<iostream>
using namespace std;
using ll = long long;

//Tags: Simulation, 反射

int main(void){
  ll n, m, s; cin >> n >> m >> s;
  ll now=s, ans=0;
  while(n--){
    char c; ll a; cin >> c >> a;
    ll x=now+a*(c=='L'?-1:1);
    if(x>=0&&x<=m){
      now=x; continue;
    }
    ans++;
    ll y=(x<0?-x:x-m);
    ll t=y/(2*m), r=y%(2*m);
    ans+=t*2-(r==0)+(r>m);
    if(x<0) now=(r<=m?r:2*m-r);
    else now=(r<=m?m-r:r-m);
  }
  cout << now << ' ' << ans << endl; 
  return 0; 
}