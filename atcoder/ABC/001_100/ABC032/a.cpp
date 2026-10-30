#include<iostream>
using namespace std;

//Tags: 整数, 最小公倍数

int gcd(int a, int b){
  if(b==0) return a;
  else return gcd(b, a%b);
}

int main(void){
  int a, b, n; cin >> a >> b >> n;
  int g=gcd(a, b);
  int lcm=a/g*b;
  int k=(n+lcm-1)/lcm;
  cout << k*lcm << endl;
  return 0;
}