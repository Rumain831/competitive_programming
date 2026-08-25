#include<iostream>
using namespace std;
using ll = long long;

//Tags: 中国剰余定理
//Level: 2

ll extgcd(ll a, ll b, ll& x, ll& y){
  if(b==0){
    x=1, y=0; return a;
  }
  ll x1, y1;
  ll gcd=extgcd(b, a%b, x1, y1);
  x=y1; y=x1-(a/b)*y1;
  return gcd;
}

//ax≡b mod m (0, -1):解なし, (0, 1):任意
pair<ll, ll> crt1(ll a, ll b, ll m){
  if(m==0) return {0, -1};
  b=(b%m+m)%m;
  if(a==0) return (b==0?make_pair(0, 1):make_pair(0, -1));
  ll x, y, g=extgcd(a, m, x, y);
  if(b%g) return {0, -1};
  a/=g, b/=g, m/=g;
  extgcd(a, m, x, y);
  ll r=b*x%m; r=(r+m)%m;
  return make_pair(r, m);
}

//ax≡b mod m1, cx≡d mod m2
pair<ll, ll> crt2(ll a, ll b, ll m1, ll c, ll d, ll m2){
  auto [r1, n1]=crt1(a, b, m1); // x≡r1 mod n1
  auto [r2, n2]=crt1(c, d, m2); // x≡r2 mod n2
  if(n1==-1||n2==-1) return {0, -1};
  r1=(r1%n1+n1)%n1, r2=(r2%n2+n2)%n2;
  if(n1==1) return {r2, n2};
  if(n2==1) return {r1, n1};
  ll x, y;
  ll g=extgcd(n1, n2, x, y);
  if(r1%g!=r2%g) return {0, -1};
  ll D=(r2-r1)/g;
  ll n2g=n2/g, inv=(x%n2g+n2g)%n2g;
  ll t=(ll)((__int128)D*inv%n2g); t=(t+n2g)%n2g;
  __int128 lcm=(__int128)(n1/g)*n2;
  __int128 ans=r1+(__int128)n1*t; ans=((ans%lcm)+lcm)%lcm;
  return {ans, lcm};
}


int main(void){
  ll n; cin >> n;
  ll p, q, r, a, b, c; cin >> p >> q >> r >> a >> b >> c;
  //x=a mod p, x=b mod q -> x=r1 mod m1
  auto [r1, m1]=crt2(1, a, p, 1, b, q);
  //x=r1 mod m1, x=c mod r -> x=r2 mod m2
  auto [r2, m2]=crt2(1, r1, m1, 1, c, r);
  if(r2>n||m2==-1){
    cout << 0 << endl; return 0;
  }
  if(r2==0) cout << n+1 << endl;
  else cout << (n-r2)/m2+1 << endl;
  return 0; 
}