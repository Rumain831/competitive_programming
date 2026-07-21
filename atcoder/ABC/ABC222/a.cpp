#include<iostream>
using namespace std;

//Tags: 文字列

int main(void){
  string n; cin >> n;
  int m=n.size();
  for(int i=0; i<4-m; i++) cout << 0;
  cout << n << endl;
  return 0; 
}
