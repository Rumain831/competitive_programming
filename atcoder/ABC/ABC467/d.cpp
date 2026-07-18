#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using i128 = __int128_t;

//垂直二等分線が平行かつ一致しないときNo

struct Point{
  ll x, y;
  Point(ll x=0, ll y=0): x(x), y(y){}
  Point operator+(const Point& o)const{return {x+o.x, y+o.y};}
  Point operator-(const Point& o)const{return {x-o.x, y-o.y};}
  Point operator*(const ll& k)const{return {x*k, y*k};}
  Point operator/(const ll& k)const{return {x/k, y/k};}
};

i128 gcd(i128 a, i128 b){
  if(b==0) return a;
  return gcd(b, a%b);
}

i128 Abs(i128 x){
  return (x<0?-x:x);
}

void solve(){
  Point p, q, r, s;
  cin >> p.x >> p.y;
  cin >> q.x >> q.y;
  cin >> r.x >> r.y;
  cin >> s.x >> s.y;
  p=p*2, q=q*2, r=r*2, s=s*2;
  Point m1=(p+q)/2, m2=(r+s)/2;
  Point t1=q-p, t2=s-r;
  i128 a1=t1.x, b1=t1.y, c1=(i128)t1.y*m1.y+(i128)t1.x*m1.x;
  i128 a2=t2.x, b2=t2.y, c2=(i128)t2.y*m2.y+(i128)t2.x*m2.x;
  i128 g1=gcd(Abs(a1), Abs(b1)); g1=gcd(g1, Abs(c1));
  i128 g2=gcd(Abs(a2), Abs(b2)); g2=gcd(g2, Abs(c2));
  a1/=g1, b1/=g1, c1/=g1; 
  if(a1<0) a1*=-1, b1*=-1, c1*=-1;
  if(a1==0){
    if(b1<0) b1*=-1, c1*=-1;
    else if(b1==0) c1=Abs(c1);
  }
  a2/=g2, b2/=g2, c2/=g2; 
  if(a2<0) a2*=-1, b2*=-1, c2*=-1;
  if(a2==0){
    if(b2<0) b2*=-1, c2*=-1;
    else if(b2==0) c2=Abs(c2);
  }
  if(a1*b2==a2*b1) cout << (c1==c2?"Yes":"No") << '\n';
  else cout << "Yes" << '\n'; 
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}