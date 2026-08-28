#include<iostream>
using namespace std;

//Tags: 実装
//Level: 1

int main(void){
  int a, b, c; cin >> a >> b >> c;
  cout << "A+B+C=" << (a+b+c==3?"Infinity":to_string(a+b+c)) << endl;
  return 0; 
}