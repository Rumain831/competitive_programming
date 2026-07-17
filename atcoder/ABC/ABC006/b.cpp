#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main(void){
  int n; cin >> n;
  int mod=10007, len=3;
  vector<int> ans={0, 0, 1};
  for(int i=3; i<n; i++){
    ans.push_back(ans[len-1]+ans[len-2]+ans[len-3]);
    len++; ans.back()%=mod;
  }
  cout << ans[n-1] << endl; 
  return 0; 
}