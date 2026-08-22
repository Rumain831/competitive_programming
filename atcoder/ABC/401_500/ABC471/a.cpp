#include<iostream>
using namespace std;

//Tags: 条件分岐

int main(void){
  int a, b; cin >> a >> b;
  if(a+b==9||a-b==9||a*b==9||b*9==a) cout << "Nine" << endl;
  else cout << "Nein" << endl;
  return 0; 
}