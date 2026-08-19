#include<iostream>
using namespace std;

//Tags: 四則演算
int main(void){
  int n, k, a; cin >> n >> k >> a;
  k=(k-1)%n;
  cout << (a-1+k)%n+1 << endl;
  return 0;
}