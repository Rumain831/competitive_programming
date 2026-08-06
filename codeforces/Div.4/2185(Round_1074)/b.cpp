#include<iostream>
using namespace std;

//Tags: 貪欲法
//https://codeforces.com/contest/2185/problem/B

void solve(){
  int n; cin >> n;
  int mx=-1;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    mx=max(mx, a);
  }
  cout << n*mx << endl;
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}