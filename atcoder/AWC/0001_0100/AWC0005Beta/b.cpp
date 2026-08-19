#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<int> s(n);
  for(auto&x:s) cin >> x;
  while(m--){
    int p, v; cin >> p >> v; p--;
    s[p]=v;
  }
  int ans=0;
  for(auto x:s)if(x<k) ans++;
  cout << ans << endl;
  return 0;
}