#include<iostream>
using namespace std;

//Tags: 条件分岐

int main(void){
  string s; cin >> s;
  int now=s.back()-'0'; s.pop_back(), s.pop_back();
  if(now<=2) cout << s << '-';
  else if(now<=6) cout << s;
  else cout << s << '+';
  return 0;
}