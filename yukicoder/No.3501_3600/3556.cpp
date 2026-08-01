#include<iostream>
#include<vector>
using namespace std;

//Tags: 条件分岐, 文字列

int main(void){
  int n; cin >> n;
  vector<string> s(n);
  for(auto&x:s) cin >> x;
  int m=11, k=n/m;
  cout << (s[k].back()=='#'?"KUPC":"KCPC") << endl;
  return 0;
}