#include<iostream>
using namespace std;

//Tags: 整数, 最大公約数

int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b, a%b);
}

int main(void){
  int n, m, g; cin >> n >> m >> g;
  int d=0;
  while(m--){
    int a; cin >> a;
    d=gcd(d, a);
  }
  int k=gcd(n, d);
  cout << (g%k?"No":"Yes") << endl;
  return 0; 
}