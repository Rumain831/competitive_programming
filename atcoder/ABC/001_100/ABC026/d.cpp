#include<iostream>
#include<math.h>
using namespace std;

//Tags: 二分探索, 数学

long double PI=atan2(1, 1)*4.0;

int main(void){
  int a, b, c; cin >> a >> b >> c;
  long double left=0, right=10000;
  int rp=60;
  auto f=[&](double t){
    return a*t+b*sin(c*PI*t);
  };
  while(rp--){
    long double mid=(left+right)/2.0;
    if(f(mid)<100) left=mid;
    else right=mid;
  }
  printf("%.10Lf\n", right);
  return 0; 
}