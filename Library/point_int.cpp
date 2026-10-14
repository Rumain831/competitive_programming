#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using i128 = __int128_t;

struct Point{
  ll x, y;
  Point(){}
  Point(ll x, ll y):x(x), y(y){}
  Point operator+(const Point& p)const{return {x+p.x, y+p.y};}
  Point operator-(const Point& p)const{return {x-p.x, y-p.y};}
  Point operator*(const ll& k)const{return {x*k, y*k};}
  Point operator-()const{return {-x, -y};}
  bool operator==(const Point& p)const{return x==p.x&&y==p.y;}
  bool operator<(const Point& p){
    if(x==p.x) return y<p.y;
    else return x<p.x;
  }
};

i128 dot(Point a, Point b){return a.x*b.x+a.y*b.y;};
i128 cross(Point a, Point b){return a.x*b.y-b.x*a.y;}
i128 norm2(Point a){return dot(a, a);}
i128 cross(Point o, Point a, Point b){return cross(a-o, b-o);}

bool parallel(Point a, Point b){return cross(a, b)==0;}
bool perp(Point a, Point b){return dot(a, b)==0;}

Point rot90(Point p){return Point(-p.y, p.x);}

template<class T>
int sgn(T x){return (x>0)-(x<0);}

//3点A, B, Cが一直線上か
bool coline(Point a, Point b, Point c){return cross(a, b, c)==0;}

//Pが線分AB上にあるか
bool onSegment(Point a, Point b, Point p){return cross(p, a, b)==0&&dot(a-p, b-p)<=0;}

//線分ABと線分PQが1点(端点除く)で交差するか
bool intersect_strict(Point a, Point b, Point p, Point q){
  return (sgn(cross(a, b, p))*sgn(cross(a, b, q))<0)&&(sgn(cross(p, q, a)*sgn(cross(p, q, b)))<0);
}

//線分ABと線分PQが共有点を持つか(端点OK)
bool intersect(Point a, Point b, Point p, Point q){
  if(onSegment(a, b, p)||onSegment(a, b, q)) return true;
  if(onSegment(p, q, a)||onSegment(p, q, b)) return true;
  return intersect_strict(a, b, p, q);
}

//Aが上半平面 or x軸正にいるなら0、下半平面 or x軸負にいるなら1
int up_down(Point a){
  return a.y<0||(a.y==0&&a.x<0);
}

//偏角ソート (0, 0)があったら壊れる！
bool cmp_arg(Point a, Point b){
  int da=up_down(a), db=up_down(b);
  if(da!=db) return da<db;
  else return cross(a, b)>0;
}

