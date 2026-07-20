#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n; cin >> n;
  vector<int> ans(n);
  for(int i=0; i<n; i++){
    int p; cin >> p; p--;
    ans[p]=i+1;
  }
  for(auto q:ans) cout << q << ' ';
  return 0;
}