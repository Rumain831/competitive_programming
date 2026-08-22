#include<iostream>
using namespace std;

//Tags: 文字列

int main(void){
  string s; cin >> s;
  for(auto p:s){
    cout << (p!='A'?'.':p);
  }
  return 0; 
}