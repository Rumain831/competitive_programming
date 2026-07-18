#include<iostream>
using namespace std;

int main(void){
  int n; cin >> n;
  int x, y; x=y=10000;
  while(n--){
    int a, b; string s; cin >> a >> b >> s;
    if(s=="take") x-=a; else x-=b;
    y-=a;
  }
  cout << y-x << endl;
  return 0; 
}