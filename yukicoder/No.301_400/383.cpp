#include<iostream>
using namespace std;

//Tags: 条件分岐
//Level: 1

int main(void){
  int a, b; cin >> a >> b;
  if(a==b) cout << 0 << endl;
  else cout << (a<b?'+':'-') << abs(a-b) << endl;
  return 0; 
}