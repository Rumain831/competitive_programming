#include<iostream>
#include<math.h>
using namespace std;
using ll=long long;
double pi=atan2(1, 1)*4.0;

//Tags: 幾何
//解説URL: https://twitter.com/e869120/status/1384276005330690049

double sq(double x, double y){return x*x+y*y;}

int main(void){
  ll T, l, x, y;
  cin >> T >> l >> x >> y;
  int q; cin >> q;
  for(int i=0; i<q; i++){
    ll e; cin >> e;
    double yk=-sin(2.0*pi*e/(double)T)*l/2.0, zk=(1.0-cos(2.0*pi*e/(double)T))*l/2.0;
    double base=sqrt(sq(x, y-yk)), ans=atan2(zk, base)*180.0/pi;
    printf("%.10f\n", ans);
  }
  return 0;
}