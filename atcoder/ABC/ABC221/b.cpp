#include<iostream>
using namespace std;

//Tags: Simulation, 文字列

int main(void){
  string s, t; cin >> s >> t;
  bool ch=false;
  int m=s.size();
  for(int i=0; i<m-1; i++){
    if(s[i]!=t[i]){
      if(ch){
        cout << "No" << endl; return 0;
      }
      ch=true;
      swap(s[i], s[i+1]);
    }
  }
  cout << (s==t?"Yes":"No") << endl;
  return 0;
}