#include<iostream>
#include<vector>
using namespace std;

//Tags: 実装
//Level: 1

void solve(){
  int n; cin >> n;
  int m=5*n;
  vector<int> a(m);
  for(auto&x:a) cin >> x;
  for(int i=0; i<m; i+=5){
    if(a[i]!=a[i+2]||a[i+1]!=a[i+3]||a[i+1]!=a[i+4]||a[i]==a[i+1]){
      cout << "No" << '\n'; return;
    }
  }
  cout << "Yes" << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}