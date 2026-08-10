#include<iostream>
using namespace std;

//Tags: コーナーケース, grid, パリティ

int main(void){
  int n, m, c; cin >> n >> m >> c;
  if(n>m) swap(n, m);
  if(n==1) cout << (m==2?"YES":"NO") << endl;
  else cout << (n*m%2?"NO":"YES") << endl;
  return 0; 
}