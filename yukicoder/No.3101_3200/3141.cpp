#include<iostream>
using namespace std;

//Tags: 括弧列
//Level: 1.5

int main(void){
  int n; string s; cin >> n >> s;
  int l=0, r=0;
  for(auto p:s){
    if(p=='(') l++;
    else r++;
  }
  cout << (l==r?"Yes":"No") << endl;
  return 0; 
}