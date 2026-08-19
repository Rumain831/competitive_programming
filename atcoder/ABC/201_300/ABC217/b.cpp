#include<iostream>
#include<set>
using namespace std;

//Tags: 全探索, 文字列

int main(void){
  set<string> p={"ABC", "ARC", "AGC", "AHC"};
  for(int i=0; i<3; i++){
    string s; cin >> s;
    p.erase(s);
  }
  cout << *p.begin() << endl;
  return 0; 
}