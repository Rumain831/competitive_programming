#include<iostream>
using namespace std;

//Tags: 幾何, 実装
//Level: 1

struct Point{
  int x, y, z;
  Point(int x, int y, int z):x(x), y(y), z(z){}
};

Point cross(Point a, Point b){
  return Point(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

int main(void){
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  auto ans=cross(Point(a, b, c), Point(d, e, f));
  printf("%d %d %d\n", ans.x, ans.y, ans.z);
  return 0;
}