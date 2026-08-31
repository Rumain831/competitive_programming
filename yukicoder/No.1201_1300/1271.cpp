#include<iostream>
#include<math.h>
using namespace std;

//Tags: 数学
//Level: 1.5

int main(void){
  int k; cin >> k;
  if(k==0){
    double PI=atan2(1, 1)*4.0;
    printf("%.10f\n", PI*PI/6);
  }
  else{
    double ans=0;
    for(int i=1; i<=k; i++) ans+=1.0/i;
    printf("%.10f\n", ans/k);
  }
  return 0; 
}