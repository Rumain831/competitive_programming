#include<iostream>
#include<vector>
#include<map>
using namespace std;

//Tags: map

int main(void){
  int n, q; cin >> n >> q;
  vector<int> a(n);
  map<int, vector<int>> mp;
  for(int i=0; i<n; i++){
    cin >> a[i];
    mp[a[i]].push_back(i+1);
  }
  while(q--){
    int x, k; cin >> x >> k;
    if(mp.count(x)==0||mp[x].size()<k){
      cout << -1 << '\n';
      continue;
    }
    cout << mp[x][k-1] << '\n';
  }
  return 0; 
}