#include<iostream>
using namespace std;

//Tags: 全探索, 文字列

int main(void){
  string s, t, u="oxx";
  for(int i=0; i<5; i++) t+=u;
  cin >> s;
  int n=s.size();
  for(int i=0; i<3; i++){
    string now=t.substr(i, n);
    if(now==s){
      cout << "Yes" << endl; return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}