#include<iostream>
using namespace std;

//Tags: 文字列

int main(void){
  int k; cin >> k;
  string s; cin >> s;
  for(auto x:s){
    int now=x-'A';
    now=(now+k)%26;
    cout << (char)('A'+now);
  }
  return 0; 
}