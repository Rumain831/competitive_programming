#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n, m; cin >> n >> m;
  vector<int> ans(m, -1);
  for(int i=0; i<n; i++){
    int c, s; cin >> c >> s; c--;
    ans[c]=max(ans[c], s);
  }
  for(auto p:ans) cout << p << ' ';
  return 0; 
}
