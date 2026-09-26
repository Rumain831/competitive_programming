#include<iostream>
using namespace std;

//Tags: 文字列

int main(void){
  string s="BYRB";
  char c; cin >> c;
  for(int i=0; i<3; i++)if(s[i]==c) cout << s[i+1];
  return 0; 
}