#include<iostream>
using namespace std;

int main(void){
  string s[3]; cin >> s[0] >> s[1] >> s[2];
  string t; cin >> t;
  for(auto p:t){
    int c=p-'1';
    cout << s[c];
  }
  return 0;
}