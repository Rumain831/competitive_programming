#include<iostream>
using namespace std;
using ll = long long;

//Tags: 四則演算
//Pythonの方が楽

int main(void){
  ll x; cin >> x;
  if(x>=0) cout << x/10 << endl;
  else cout << -(-x+9)/10 << endl;
  return 0;
}