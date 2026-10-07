#include<iostream>
using namespace std;
using ll = long long;

//Tags: 期待値, grid, 場合分け
//Level: 2

int main(void){
  ll n, m; double p; cin >> n >> m >> p;
  if(n>m) swap(n, m);
  double p2=p*p, p3=p2*p, p4=p2*p2, p5=p4*p;
  if(n==1){
    if(m==1){printf("%.10f\n", p); return 0;}
    int c1=2, c2=m-2;
    printf("%.10f\n", p2*c1+p3*c2);
    return 0;
  }
  ll c2=4, c3=2*(n+m-4), c4=n*m-c2-c3;
  printf("%.10f\n", p3*c2+p4*c3+p5*c4);
  return 0; 
}