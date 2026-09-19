#include<iostream>
using namespace std;

//Tags: 条件を満たすものの個数
//Level: 1

int main(void){
  int c=0, n=8;
  while(n--){
    string s; cin >> s;
    if(s=="AC"||s=="NoOut") c++;
  }
  if(c>=6) cout << "Win" << endl;
  else cout << (c==5?"Draw":"Lose") << endl;
  return 0; 
}