#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation

int main(void){
  int n, q; cin >> n >> q;
  vector<int> ans(n);
  for(int i=0; i<n; i++) ans[i]=i+1;
  while(q--){
    vector<int> old=ans;
    int k; cin >> k;
    for(int i=0; i<k; i++) ans[i]=old[k-1-i]*(-1);
  }
  for(auto p:ans) cout << p << '\n';
  return 0; 
}