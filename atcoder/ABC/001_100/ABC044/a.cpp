#include<iostream>
using namespace std;

//Tags: 四則演算

int main(void){
  int n, k, x, y; cin >> n >> k >> x >> y;
  cout << min(n, k)*x+max(0, n-k)*y << endl;
  return 0; 
}