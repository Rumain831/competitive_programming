#include<iostream>
using namespace std;

//Tags: 文字列
//Level: 1

int main(void){
  string s; int t, u; cin >> s >> t >> u; 
  for(int i=0; i<s.size(); i++){
    if(i!=t&&i!=u) cout << s[i];
  }cout << endl;
  return 0; 
}