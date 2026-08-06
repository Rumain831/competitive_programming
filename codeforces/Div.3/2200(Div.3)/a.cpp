#include<iostream>
using namespace std;

//Tags: 条件を満たすものの個数
//https://codeforces.com/contest/2200/problem/A

void solve(){
  int n; cin >> n;
  int mx=-1, ans=0;
  while(n--){
    int a; cin >> a;
    if(mx<a) mx=a, ans=1;
    else if(mx==a) ans++;  
  }
  cout << ans << endl;
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}