#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: 有理数, 実装
//Level: 1.5

int main(void){
  int n; cin >> n;
  vector<P> ans;
  for(int i=0; i<n; i++){
    int a, b; cin >> a >> b;
    ans.emplace_back(a, b);
  }
  sort(begin(ans), end(ans), [](const P& a, const P& b){
    return a.first*b.second>a.second*b.first;
  });
  for(auto [a, b]:ans) cout << a << ' ' << b << endl;
  return 0; 
}