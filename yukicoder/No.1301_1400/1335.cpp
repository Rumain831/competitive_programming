#include<iostream>
using namespace std;

//Tags: 文字列
//Level: 1

int main(void){
  string a, s; cin >> a >> s;
  for(auto&p:s){
    if(isdigit(p)){
      int now=p-'0';
      p=a[now];
    }
  }
  cout << s << endl;
  return 0; 
}