#include<iostream>
using namespace std;

//Tags: 文字列
//Level: 1

int main(void){
  string s; cin >> s;
  for(auto p:s){
    if(islower(p)) cout << (char)toupper(p);
    else cout << (char)tolower(p);
  }
  return 0; 
}