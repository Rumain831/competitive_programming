#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: ソート

int main(void){
  int n; cin >> n;
  vector<pair<int, int>> s;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    s.emplace_back(a, i+1);
  }
  sort(rbegin(s), rend(s));
  for(auto p:s) cout << p.second << '\n';
  return 0;
}