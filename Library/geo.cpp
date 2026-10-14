#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
using ll = long long;

using ld = long double;
const ld eps = 1e-12;
int sgn(ld x){if(abs(x)<=eps)return 0; return (x>0?1:-1);}
bool eq(ld a, ld b){return abs(a-b)<=eps*(1.0+max(abs(a), abs(b)));}

struct Point{
  ld x, y;
  Point(ld x=0, ld y=0): x(x), y(y){}
  Point operator+(const Point& o)const{return {x+o.x, y+o.y};}
  Point operator-(const Point& o)const{return {x-o.x, y-o.y};}
  Point operator*(const ld& k)const{return {x*k, y*k};}
  Point operator/(const ld& k)const{return {x/k, y/k};}
  bool operator==(const Point& o)const{return eq(x, o.x)&&eq(y, o.y);}
};

ld dot(Point a, Point b){return a.x*b.x+a.y*b.y;}
ld cross(Point a, Point b){return a.x*b.y-a.y*b.x;}
ld normsq(Point a){return dot(a, a);}
ld norm(Point a){return sqrtl(dot(a, a));}
Point unit(Point a){ld l=norm(a); return l==0?a:a/l;}

int side(Point tar, Point a, Point b){ //+1 ABの左側, -1 右側, 0 上
  return sgn(cross(b-a, tar-a));
}
bool online(Point tar, Point a, Point b){return (side(tar, a,  b)==0);} //直線AB上にあるか
bool onseg(Point tar, Point a, Point b){ //線分AB上にあるか
  if(side(tar, a, b)!=0) return false;
  else return (sgn(dot(tar-a, tar-b))<=0);
}
bool intersectSS(Point a, Point b, Point c, Point d){ //線分AB, CDが共有点を持つか
  int s=side(a, c, d)*side(b, c, d);
  int t=side(c, a, b)*side(d, a, b);
  if(s*t==0){
    bool on=onseg(a, c, d)||onseg(b, c, d)||onseg(c, a, b)||onseg(d, a, b);
    return on;
  }
  else return (s<0&&t<0);
}

Point proj(Point p, Point a, Point b){
  Point ab=b-a;
  ld t=dot(ab, p-a)/normsq(ab);
  return a+ab*t;
}
Point ref(Point p, Point a, Point b){
  Point q=proj(p, a, b);
  return q*2-p;
}

ld dist_ptol(Point p, Point a, Point b){ //点Pと直線ABとの距離
  return abs(cross(b-a, p-a))/norm(b-a);
}
ld dist_ptos(Point p, Point a, Point b){ //点Pと線分ABとの距離
  Point ab=b-a;
  ld t=dot(ab, p-a)/normsq(ab);
  if(t<0) return norm(p-a);
  else if(t>1) return norm(p-b);
  else return abs(cross(b-a, p-a))/norm(b-a);
}

template<class co=ll>
long double norm(vector<co> a){
  return (long double)sqrtl(a[0]*a[0]+a[1]*a[1]);
}

template<class co=ll>
long double dist(vector<co> p, vector<co> a, vector<co> b, int type){ //type 0：直線AB, 1：線分AB
  vector<co> ab={b[0]-a[0], b[1]-a[1]};
  vector<co> ap={p[0]-a[0], p[1]-a[1]};
  vector<co> bp={p[0]-b[0], p[1]-b[1]};
  //(yb-ya)(x-xa)+(xa-xb)(y-ya)=0
  co s=b[1]-a[1], t=a[0]-b[0], u=-a[0]*s-a[1]*t;
  co dot=ab[0]*ap[0]+ab[1]*ap[1];
  long double AB=norm(ab), AP=norm(ap), BP=norm(bp);
  if(s==0&&t==0) return AP;
  long double PH=abs(s*p[0]+t*p[1]+u)/sqrtl(s*s+t*t);
  if(type){
    if(dot<=0) return AP;
    else if(dot>=ab[0]*ab[0]+ab[1]*ab[1]) return BP;
    else return PH;
  }
  else return PH;
}

int main(void){

}