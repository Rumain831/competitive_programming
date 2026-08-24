#include<iostream>
#include<math.h>
using namespace std;

//Tags: 幾何
//Level: 2

int main(void){
  int a, b, c; cin >> a >> b >> c;
  double s=(a+b+c)/2.0;
  double S=sqrt(s*(s-a)*(s-b)*(s-c));
  printf("%.10f\n", 2.0*S/(a+b+c));
  return 0;
}