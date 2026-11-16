#include<iostream>
using namespace std;

//Tags: 文字列

int main(void){
  int n, k; cin >> n >> k;
  string ans;
  while(ans.size()<n){
    ans+=string(k, 'R');
    ans+=string(k, 'B');
  }
  while(ans.size()>n) ans.pop_back();
  cout << ans << endl;
  return 0; 
}