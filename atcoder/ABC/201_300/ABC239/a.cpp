#include<iostream>
#include<math.h>
using namespace std;
using ll = long long;

//Tags: 数学

int main(void){
  ll h; cin >> h;
  ll p=h*(12800000+h);
  printf("%.10f", sqrt(p));
  return 0;
}