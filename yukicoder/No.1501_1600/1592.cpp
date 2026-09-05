#include<iostream>
#include<algorithm>
using namespace std;

//Tags: 文字列
//Level: 1.5

int main(void){
  string s; cin >> s;
  string t="kyoprotenkei90";
  sort(begin(s), end(s));
  sort(begin(t), end(t));
  cout << (s==t?"Yes":"No") << endl;
  return 0; 
}