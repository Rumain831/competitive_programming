#include<iostream>
using namespace std;

//Tags: Simulation

int main(void){
  int n; cin >> n;
  int pre=-1;
  while(n--){
    int a; cin >> a;
    if(pre!=a){
      cout << a << '\n'; pre=a;
    }
  }
  return 0; 
}