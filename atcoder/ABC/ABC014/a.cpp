#include<iostream>
using namespace std;

int main(void){
  int a, b; cin >> a >> b;
  cout << (a+b-1)/b*b-a << endl;
  return 0;
}