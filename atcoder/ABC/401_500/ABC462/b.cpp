#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n; cin >> n;
  vector<vector<int>> ans(n);
  for(int i=0; i<n; i++){
    int k; cin >> k;
    while(k--){
      int x; cin >> x; x--;
      ans[x].push_back(i+1);
    }
  }
  for(int i=0; i<n; i++){
    cout << ans[i].size() << ' ';
    for(auto p:ans[i]) cout << p << ' ';
    cout << endl;
  }
  return 0; 
}