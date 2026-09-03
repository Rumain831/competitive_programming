#include<iostream>
using namespace std;

//Tags: 括弧列
//Level: 2

int main(void){
  int n; string s; cin >> n >> s;
  int x=0;
  for(auto p:s){
    if(p=='(') x++;
    else{
      if(x==0){
        cout << "No" << endl; return 0;
      }
      x--;
    }
  }
  cout << (x==0?"Yes":"No") << endl;
  return 0; 
}