#include<iostream>
using namespace std;
using ll = long long;

//Tags: メビウス関数
//Level: 2.5
//正の約数の総和の公式 (1+p1+p1^2+...)(1+p2+p2^2+...)... を
//pi->-1, pi^2以降->0 に置き換えると mu(正の約数)の総和 が得られる。
//1つでも素因数があれば(1-1)が掛けられ0になる。N=1のときだけ1が残る。

ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}

int main(void){
  ll a, b; cin >> a >> b;
  cout << (gcd(a, b)==1?1:0) << endl;
  return 0; 
}