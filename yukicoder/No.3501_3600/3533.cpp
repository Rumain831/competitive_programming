#include<iostream>
using namespace std;

//Tags: grid
//Level: 1
//n=1なら1通り。
//n>=2なら、最初に右に進む経路は、対角線で折り返すことで最初に下に進む経路と一対一対応する。
//よって経路数は偶数となる。

int main(void){
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    cout << (n==1) << '\n';
  }
  return 0; 
}