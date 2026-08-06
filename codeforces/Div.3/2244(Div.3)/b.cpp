#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 単調増加
//https://codeforces.com/contest/2244/problem/B

void solve(){
  int n; cin >> n;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  for(int i=0; i<n; i++){
    if(a[i]<i+1){
      cout << "NO" << '\n'; return;
    }
    if(i==n-1){
      cout << "YES" << '\n'; return;
    }
    ll add=a[i]-i-1;
    a[i+1]+=add;
  }
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}