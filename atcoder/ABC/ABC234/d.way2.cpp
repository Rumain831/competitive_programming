#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Tags: Simulation
//setを使い、大きい値K個を実際に管理する方法

int main(void){
  int n, k; cin >> n >> k;
  vector<int> p(n);
  set<int> pre, aft;
  for(auto&x:p) cin >> x;
  for(int i=0; i<k-1; i++) pre.insert(p[i]);
  for(int i=k-1; i<n; i++){
    pre.insert(p[i]);
    if(pre.size()>k){
      auto it=pre.begin();
      aft.insert(*it);
      pre.erase(it);
    }
    cout << *pre.begin() << '\n';
  }
  return 0; 
}