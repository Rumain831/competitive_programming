#include<iostream>
using namespace std;

//Tags: 整数, 不定方程式

int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b, a%b);
}

int main(void){
  int a, b; cin >> a >> b;
  int g=gcd(a, b);
  if(g!=1){
    cout << -1 << endl; return 0;
  }
  cout << (a-1)*(b-1)/2 << endl;
  return 0; 
}