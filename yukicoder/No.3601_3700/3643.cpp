#include<iostream>
using namespace std;
using ll = long long;

//Tags: 期待値
//Level: 2.5
//f(i)=i*choose(n-b, i)/choose(n, i)が最大となるiを求める問題
//f(i)/f(i+1) >= 1 などを計算すると　i=ceil((n-b)/(b+1)) と分かる

int main(void){
  int t; cin >> t;
  while(t--){
    ll n, b; cin >> n >> b;
    cout << n/(b+1) << '\n';
  }
  return 0;
}