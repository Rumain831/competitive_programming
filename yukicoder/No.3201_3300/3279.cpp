#include<iostream>
using namespace std;

//Tags: 条件分岐
//Level: 1

int a[5]={390,429,468,507,546};
int main(void){
  int l; string s; cin >> l >> s;
  if(s[0]=='B') l++;
  cout << a[l-1] << endl;
  return 0; 
}