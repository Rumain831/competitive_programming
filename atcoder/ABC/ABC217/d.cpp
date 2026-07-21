#include<iostream>
#include<set>
using namespace std;

//Tags: Simulation

int main(void){
  int l, q; cin >> l >> q;
  set<int> cut={0, l};
  while(q--){
    int t, x; cin >> t >> x;
    if(t==1){
      cut.insert(x);
    }
    else{
      auto p=cut.lower_bound(x);
      auto q=p; q--;
      cout << *p-*q << '\n';
    }
  }
  return 0;
}