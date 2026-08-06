#include<iostream>
#include<vector>
using namespace std;

//Tags: 全探索, XOR
//https://codeforces.com/contest/2218/problem/E
//実験により、最後に残る2要素のXORが、操作終了後に残る値になることが分かる。

void solve(){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  int ans=0;
  for(int i=0; i<n-1; i++)for(int j=i+1; j<n; j++){
    ans=max(ans, a[i]^a[j]);
  }
  cout << ans << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}