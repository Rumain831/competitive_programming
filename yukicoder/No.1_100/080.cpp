#include<iostream>
using namespace std;

//Tags: 幾何
//縦+横=floor(d/2) 

int main(void){
  int d; cin >> d; d/=2;
  int tate=d/2, yoko=d-tate;
  cout << tate*yoko << endl;
  return 0; 
}