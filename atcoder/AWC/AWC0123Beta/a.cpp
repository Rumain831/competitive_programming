#include<iostream>
using namespace std;
using ll = long long;

//Tags: 条件分岐

int main(void){
  int n, m; cin >> n >> m;
  ll ans=0;
  for(int i=0; i<n; i++){
    ll a; cin >> a;
    if(0<=a&&a<=m) continue;
    ans+=min(abs(a), abs(m-a));
  }
  cout << ans << endl;
  return 0; 
}