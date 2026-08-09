#include<iostream>
using namespace std;

//Tags: 漸化式
//三項間漸化式を解けば an=4*(3/4)^n が得られる。

int main(void){
  int n; cin >> n;
  double r=3.0/4, ans=4;
  while(n--){
    ans*=r;
  }
  printf("%.10f\n", ans);
  return 0; 
}