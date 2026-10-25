#include<iostream>
using namespace std;

//Tags: 四則演算, 時計

int main(void){
  int n, m; cin >> n >> m; n%=12;
  double sh=6.0*m, lo=30.0/60.0*m+n*30.0;
  double p=abs(lo-sh);
  double ans=min(p, 360.0-p);
  printf("%.10f\n", ans);
  return 0;
}