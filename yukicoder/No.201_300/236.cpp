#include<iostream>
using namespace std;

//Tags: 四則演算
//Level: 1.5
//どちらか片方をmaxまで使わないと最大にならない

int main(void){
  double a, b, x, y; cin >> a >> b >> x >> y;
  double ans=0;
  if(x*b<=y*a) ans+=x*(1.0+b/a);
  else ans+=y*(1.0+a/b);
  printf("%.10f\n", ans);
  return 0; 
}