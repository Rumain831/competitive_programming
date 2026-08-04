#include<iostream>
using namespace std;

//Tags: 条件分岐
//https://codeforces.com/contest/2227/problem/A

//両者とも奇数なら不可能、そうでないなら可能
void solve(){
  int x, y; cin >> x >> y;
  int cnt=(x&1)+(y&1);
  cout << (cnt<=1?"Yes":"No") << endl;
};

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}
