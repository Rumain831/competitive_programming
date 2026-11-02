#include<iostream>
using namespace std;

//Tags: 文字列, Simulation

int main(void){
  int n, q; string s; cin >> n >> q >> s;
  while(q--){
    int a, b; cin >> a >> b; a--, b--;
    swap(s[a], s[b]);
  }
  cout << s << endl;
  return 0; 
}