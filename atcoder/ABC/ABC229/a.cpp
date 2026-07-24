#include<iostream>
using namespace std;

//Tags: 条件分岐

int main(void){
  string s, t; cin >> s >> t;
  string u=s+t;
  if(u=="#..#"||u==".##.") cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}