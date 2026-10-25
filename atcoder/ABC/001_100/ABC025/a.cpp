#include<iostream>
using namespace std;

//Tags: 文字列, 辞書順

int main(void){
  string s; cin >> s;
  int n; cin >> n; n--;
  int p=n/5, r=n%5;
  cout << s[p] << s[r] << endl;
  return 0;
}