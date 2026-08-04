#include<iostream>
#include<vector>
using namespace std;

//Tags: 考察で瞬殺
//既に広義単調増加なら答えはn。
//そうでないならi<jだがai>ajなる(i, j)がある。
//上手く操作すればaiだけ残せる。

void solve(){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  bool nondec=true;
  for(int i=0; i<n-1; i++){
    if(a[i]>a[i+1]){
      nondec=false; break;
    }
  }
  cout << (nondec?n:1) << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}