#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: Simulation
//Level: 1

int main(void){
  int n, m; cin >> n >> m;
  vector<int> c(n);
  for(auto&x:c) cin >> x;
  sort(begin(c), end(c));
  int ans=0;
  for(int i=0; i<n; i++){
    if(c[i]<=m) m-=c[i], ans++;
    else break;
  }
  cout << ans << endl;
  return 0; 
}