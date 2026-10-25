#include<iostream>
using namespace std;

//Tags: 条件分岐

int main(void){
  int a, b, c, d; cin >> a >> b >> c >> d;
  if(b*c==a*d) cout << "DRAW" << endl;
  else cout << (b*c>a*d?"TAKAHASHI":"AOKI") << endl;
  return 0; 
}