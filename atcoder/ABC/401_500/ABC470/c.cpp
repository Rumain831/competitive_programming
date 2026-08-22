#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Tags: Simulation, XOR

int main(void){
  int n, q; cin >> n >> q;
  int ans=0;
  vector<int> a(n);
  set<int> over;
  while(q--){
    int t; cin >> t;
    if(t==1){
      int x; cin >> x; x--;
      ans^=a[x];
      a[x]++;
      ans^=a[x];
      over.insert(x);
    }
    else{
      auto it=over.begin();
      while(it!=over.end()){
        int id=*it;
        ans^=a[id];
        a[id]--;
        ans^=a[id];
        if(a[id]==0) it=over.erase(it);
        else it++;
      }
    }
    cout << ans << '\n';
  }
  return 0; 
}