#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using i128 = __int128_t;

//Tags: 偏角ソート

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

i128 cross(Point a, Point b){return a.x*b.y-b.x*a.y;}

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

void solve(){
  int n; cin >> n;
  vector<Point> p;
  for(int i=0; i<n; i++){
    ll x, y; cin >> x >> y;
    p.emplace_back(x, y);
  }
  sort(begin(p), end(p), cmp_arg);
  int ans=0;
  for(int i=0; i<n; i++){
    Point far=(up_down(p[i])?p[i]:-p[i]), now=-far;
    int k=upper_bound(begin(p), end(p), far, cmp_arg)-lower_bound(begin(p), end(p), now, cmp_arg);
    ans=max(ans, max(k, n-k+1));
  }
  cout << ans << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}