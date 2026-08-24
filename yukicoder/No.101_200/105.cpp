#include<iostream>
#include<math.h>
using namespace std;

//Tags: 幾何, 小数の扱い
//Level: 2.5

void solve(){
  long double ans;
  for(int i=0; i<6; i++){
    long double x, y; cin >> x >> y;
    long double theta=atan2(y, x)*45.0/atan2(1, 1);
    if(-5<theta&&theta<55){
      ans=max<long double>(0, theta);
    }
  }
  printf("%.10Lf\n", ans);
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}