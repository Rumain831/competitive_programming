#include<iostream>
using namespace std;

//Tags: 文字列
//Level: 1

int main(void){
  int n; string s; cin >> n >> s;
  int x; char c; cin >> x >> c;
  s[x-1]=c;
  cout << s << endl;
  return 0; 
}