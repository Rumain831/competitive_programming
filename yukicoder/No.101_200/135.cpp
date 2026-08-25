#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 実装
//Level: 1

int main(void){
  int n; cin >> n;
  vector<int> x(n);
  for(auto&y:x) cin >> y;
  sort(begin(x), end(x));
  x.erase(unique(begin(x), end(x)), end(x));
  if(x.size()==1){
    cout << 0 << endl; return 0;
  }
  n=x.size();
  int ans=1e9;
  for(int i=0; i<n-1; i++) ans=min(ans, x[i+1]-x[i]);
  cout << ans << endl;
  return 0; 
}