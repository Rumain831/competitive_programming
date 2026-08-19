#include<iostream>
using namespace std;

int main(void){
  string s; cin >> s;
  for(auto p:s)if(isdigit(p)) cout << p;
  return 0; 
}