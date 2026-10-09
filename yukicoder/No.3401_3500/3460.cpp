#include<iostream>
using namespace std;
using ll = long long;

//Tags: ゲーム
//Level: 2.5
//小さいnでdpを書けば予想ができる

void solve(){
  ll n; cin >> n;
  while(n){
    if(!(n&1)){
      cout << "Alice" << endl; return;
    }
    n/=2;
  }
  cout << "Bob" << endl;
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}