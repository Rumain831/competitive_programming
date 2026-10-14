#include<iostream>
#include<vector>
using namespace std;
using P = pair<int, int>;

//Tags: Simulation

int main(void){
  int n; cin >> n;
  vector<P> a(1<<n);
  int c=0;
  for(auto&[x, y]:a) cin >> x, y=c++;
  vector<int> ans(1<<n);
  for(int i=0; i<n; i++){
    vector<P> old;
    swap(old, a);
    int m=old.size();
    for(int j=0; j<m; j+=2){
      auto [a1, i1]=old[j];
      auto [a2, i2]=old[j+1];
      ans[i1]=ans[i2]=i+1;
      if(a1>a2) a.push_back(old[j]);
      else a.push_back(old[j+1]);
    }
  }
  for(auto p:ans) cout << p << '\n';
  return 0; 
}