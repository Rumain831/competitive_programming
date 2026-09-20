#include<iostream>
using namespace std;

//Tags: 確率
//Level: 1.5

int main(void){
  double p, q; cin >> p >> q;
  //裏->表
  double p1=(1.0-p)*q;
  //表->裏->表
  double p2=p*(1.0-q)*q;
  cout << (p1<p2?"YES":"NO") << endl;
  return 0; 
}