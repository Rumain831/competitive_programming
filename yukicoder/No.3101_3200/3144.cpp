#include<iostream>
using namespace std;

//Tags: 括弧列, 考察で瞬殺
//Level: 2.5

int main(void){
  int n, r, m; string s; cin >> n >> s >> r >> m;
  if(n&1){
    cout << -1 << endl; return 0;
  }
  int l=0;
  for(auto p:s) l+=(p=='(');
  cout << abs(l-n/2) << endl;
  return 0; 
}