#include<iostream>
using namespace std;

int main(void){
  string s; cin >> s;
  string tar="aiueo";
  for(int i=0; i<s.size(); i++){
    if(tar.find(s[i])==string::npos) cout << s[i];
  }
  cout << endl;
  return 0;
}