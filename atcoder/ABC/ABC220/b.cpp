#include<iostream>
using namespace std;
using ll = long long;

//Tags: 整数, n進数

int main(void){
  int k; cin >> k;
  string a, b; cin >> a >> b;
  auto p=stoll(a, nullptr, k);
  auto q=stoll(b, nullptr, k);
  cout << p*q << endl;
  return 0;
}