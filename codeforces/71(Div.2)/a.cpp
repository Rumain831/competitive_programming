#include<iostream>
using namespace std;

//Tags: 文字列
//https://codeforces.com/contest/71/problem/A

int main(void){
  int n; cin >> n;
  for(int i=0; i<n; i++){
    string s; cin >> s;
    if(s.size()<=10) cout << s << endl;
    else cout << s[0] << s.size()-2 << s.back() << endl;
  }
  return 0; 
}
