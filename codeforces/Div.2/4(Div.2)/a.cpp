#include<iostream>
using namespace std;

//Tags: 条件分岐
//https://codeforces.com/contest/4/problem/A

int main(void){
  int w; cin >> w;
  if(w%2) cout << "NO" << endl;
  else if(w==2) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0; 
}