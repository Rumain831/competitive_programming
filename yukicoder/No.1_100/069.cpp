#include<iostream>
#include<algorithm>
using namespace std;

//Tags: 文字列
//Level: 1

int main(void){
  string a, b; cin >> a >> b;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  cout << (a==b?"YES":"NO") << endl;
  return 0; 
}