#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Tags: 数列

int main(void){
  int n; cin >> n;
  set<vector<int>> p;
  for(int i=0; i<n; i++){
    vector<int> now;
    int l; cin >> l;
    for(int j=0; j<l; j++){
      int a; cin >> a;
      now.push_back(a);
    }
    p.insert(now);
  }
  cout << p.size() << endl;
  return 0;
}