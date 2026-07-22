#include<iostream>
using namespace std;

//Tags: 小数の扱い

int main(void){
  string s; cin >> s;
  int n=s.size(), dot, m=0;
  for(int i=0; i<n; i++){
    if(s[i]=='.'){dot=i; break;}
    int now=s[i]-'0';
    m=10*m+now;
  }
  if(s[dot+1]>='5') m++;
  cout << m << endl;
  return 0;
}