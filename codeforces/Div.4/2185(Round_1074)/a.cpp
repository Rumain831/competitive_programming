#include<iostream>
using namespace std;

//Tags: 整数
//https://codeforces.com/contest/2185/problem/A

void solve(){
  int n; cin >> n;
  for(int i=1; i<=n; i++) cout << i << (i==n?'\n':' ');
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}