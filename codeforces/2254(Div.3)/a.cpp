#include<iostream>
#include<algorithm>
using namespace std;

//Tags: Simulation
//https://codeforces.com/contest/2254/problem/A

void solve(){
  int a[3]; cin >> a[0] >> a[1] >> a[2];
  int ans=0;
  sort(a, a+3);
  while(1){
    if(a[0]==a[1]||a[1]==a[2]) break;
    a[2]--, a[0]++; ans++;
    sort(a, a+3);
  }
  cout << ans << endl;
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}