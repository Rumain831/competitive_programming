#include<iostream>
using namespace std;

//Tags: 文字列

int main(void){
  string s; cin >> s;
  int a, b; cin >> a >> b, a--, b--;
  swap(s[a], s[b]);
  cout << s << endl;
  return 0;
}