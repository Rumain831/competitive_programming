#include<iostream>
using namespace std;
using ll = long long;

//Tags: 数え上げ, 回文
//奇数番目の異なる位置2つ, 偶数番目の異なる位置2つの選び方の和が答え

int main(void){
  ll l; cin >> l;
  ll even=l/2, odd=l-even;
  ll ans=even*(even-1)/2+odd*(odd-1)/2;
  cout << ans << endl;
  return 0; 
}