#include<iostream>
#include<set>
using namespace std;

//Tags: 実装
//Level: 1

int main(void){
  int n; cin >> n;
  set<pair<int, int>> p;
  for(int i=0; i<n; i++){
    int a, b; cin >> a >> b;
    p.insert({a, b});
  }
  cout << ((int)p.size()==n?"No":"Yes") << endl;
  return 0;
}