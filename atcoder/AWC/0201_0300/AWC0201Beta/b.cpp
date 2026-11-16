#include<iostream>
#include<algorithm>
using namespace std;

//Tags: 文字列, 回文

int main(void){
  int n; string s; cin >> n >> s;
  string t=s;
  reverse(begin(t), end(t));
  cout << (s==t?"Yes":"No") << endl;
  return 0; 
}