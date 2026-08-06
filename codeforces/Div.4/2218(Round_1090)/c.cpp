#include<iostream>
using namespace std;

//Tags: 順列, 中央値, 構築
//https://codeforces.com/contest/2218/problem/C

void solve(){
  int n; cin >> n;
  int m=3*n, med=m-1;
  for(int i=0; i<n; i++){
    cout << i+1 << ' ' << med << ' ' << med+1 << ' ';
    med-=2;
  }
  cout << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}