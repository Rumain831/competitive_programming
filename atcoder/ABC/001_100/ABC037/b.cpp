#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation

int main(void){
  int n, q; cin >> n >> q;
  vector<int> a(n);
  while(q--){
    int l, r, t; cin >> l >> r >> t; l--, r--;
    for(int i=l; i<=r; i++) a[i]=t;
  }
  for(auto p:a) cout << p << ' '; cout << endl;
  return 0;
}
