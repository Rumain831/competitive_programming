#include<iostream>
using namespace std;

//Tags: 文字列

int main(void){
  string s;
  for(int i=0; i<26; i++){
    int p; cin >> p; p--;
    s+=(char)('a'+p);
  }
  cout << s << endl;
  return 0; 
}