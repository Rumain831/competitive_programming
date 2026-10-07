#include<iostream>
using namespace std;

//Tags: 数え上げ, ビット演算
//Level: 2

int main(void){
  int a, b; cin >> a >> b;
  if((a&b)!=a){
    cout << 0 << endl; return 0;
  }
  int k=__builtin_popcount(a);
  int m=__builtin_popcount(a^b);
  if(m) cout << (1<<(m-1)) << endl;
  else cout << 1 << endl;
  return 0; 
}