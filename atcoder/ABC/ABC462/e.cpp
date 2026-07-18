#include<iostream>
using namespace std;
using ll = long long;
void chmin(ll& a, ll b){a=min(a, b);}

ll f(ll a, ll b, ll x, ll y){
  if(x==0&&y==0) return 0ll;
  if(x<0) x*=-1;
  if(y<0) y*=-1;
  if(x==y) return x*2*a;
  ll ans=(x+y)*b+10;
  if(x>=y){
    ll now=2ll*a*y;
    ll X=x-y;
    ll p=X-1; p+=(p&1);
    chmin(ans, now+X/2*(a+b)+(X&1)*a);
    chmin(ans, now+(X+p)*a);
  }
  else{
    ll now=2ll*a*x;
    ll Y=y-x;
    ll p=(Y&1?Y+1:Y);
    chmin(ans, now+Y/2*(a+b)+(Y&1)*b);
    chmin(ans, now+(Y+p)*a);
  }
  return ans;
}

void solve(){
  ll a, b, x, y; cin >> a >> b >> x >> y;
  if(x==0&&y==0){
    cout << 0 << '\n'; return;
  }
  if(a<=b){
    cout << f(a, b, x, y) << '\n';
  }
  else{
    ll ans=a*(abs(x)+abs(y));
    chmin(ans, a+f(b, a, x-1, y));
    chmin(ans, a+f(b, a, x+1, y));
    chmin(ans, b+f(b, a, x, y-1));
    chmin(ans, b+f(b, a, x, y+1));
    cout << ans << '\n';
  }
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}