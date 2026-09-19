#include<iostream>
using namespace std;

//Tags: 文字列

int main(void){
  int n; string s, t; cin >> n >> s >> t;
  for(int i=0; i<n; i++){
    if(s[i]==t[i]) continue;
    if(t[i]=='*') continue;
    if(s[i]!=t[i]){
      cout << "No" << endl; return 0;
    }
  } 
  cout << "Yes" << endl;
  return 0; 
}