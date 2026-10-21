#include<iostream>
using namespace std;

//Tags: 期待値
//Level: 3

int main(void){
  int n; cin >> n;
  if(n<=4){
    cout << 0 << endl; return 0;
  }
  double p=1;
  for(int i=0; i<5; i++) p*=(n-i)/(99.0-i);
  printf("%.10f\n", p*12,0);
  return 0; 
}