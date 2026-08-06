#include<iostream>
using namespace std;

//Tags: 全探索
//https://codeforces.com/contest/2218/problem/B

void solve(){
  int a[7];
  int ans=-1e9, sum=0;
  for(int i=0; i<7; i++) cin >> a[i], sum-=a[i];
  for(int i=0; i<7; i++){
    int now=sum+2*a[i];
    ans=max(ans, now);
  }
  cout << ans << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}