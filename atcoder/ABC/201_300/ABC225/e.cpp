#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using i128 = __int128_t;

//Tags: 偏角ソート, 区間スケジューリング, 貪欲法

struct Point{
  ll x, y;
  Point(){}
  Point(ll x, ll y):x(x), y(y){}
  Point operator+(const Point& p)const{return {x+p.x, y+p.y};}
  Point operator-(const Point& p)const{return {x-p.x, y-p.y};}
  Point operator*(const ll& k)const{return {x*k, y*k};}
  Point operator-()const{return {-x, -y};}
  bool operator==(const Point& p)const{return x==p.x&&y==p.y;}
  bool operator!=(const Point& p)const{return !(*this==p);}
  bool operator<(const Point& p){
    if(x==p.x) return y<p.y;
    else return x<p.x;
  }
};
using P = pair<Point, Point>;

i128 cross(Point a, Point b){return a.x*b.y-b.x*a.y;}

bool cmp_arg(Point a, Point b){ //第1象限のみなのでこれで十分
  return cross(a, b)>0;
}

int main(void){
  int n; cin >> n;
  vector<P> hu;
  for(int i=0; i<n; i++){
    int x, y; cin >> x >> y;
    Point up(x-1, y), down(x, y-1);
    hu.emplace_back(up, down);
  }
  sort(begin(hu), end(hu), [&](const P& p, const P& q){
    auto [pu, pd]=p;
    auto [qu, qd]=q;
    if(pu!=qu) return cmp_arg(pu, qu);
    else return cmp_arg(pd, qd);
  });
  int ans=0, id=0;
  while(id<n){
    Point now=hu[id].first; ans++;
    while(id<n){
      auto [pu, pd]=hu[id];
      if(cmp_arg(pd, now)) id++;
      else break;
    }
  }
  cout << ans << endl;
  return 0; 
}