#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation

int main(void){
  int n, m; cin >> n >> m;
  vector<int> cnt(n);
  int ans=0, mx=0;
  while(m--){
    int p; cin >> p; p--;
    cnt[p]++;
    if(p!=1) mx=max(mx, cnt[p]);
    else ans+=(mx>cnt[p]);
  }
  cout << ans << endl;
  return 0; 
}