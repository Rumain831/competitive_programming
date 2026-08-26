#include<iostream>
using namespace std;

//Tags: 整数
//Level: 2
//B+x=(A+x)k をxについて解くと、x=(B-A)/(k-1)-A。つまり、(B-Aの約数)-Aの形になっている。

void solve(){
  int a, b; cin >> a >> b;
  if(a==b){
    cout << 0 << '\n'; return;
  }
  int c=b-a;
  int ans=2e9;
  for(int i=1; i*i<=c; i++){
    if(c%i) continue;
    if(i>=a) ans=min(ans, i-a);
    if(c/i>=a) ans=min(ans, c/i-a);
  }
  cout << (ans==2e9?-1:ans) << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}