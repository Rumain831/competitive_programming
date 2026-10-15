#include<iostream>
#include<vector>
using namespace std;

//Tags: 文字列, Simulation
//Level: 1

int main(void){
  int n; string s; cin >> n >> s;
  vector<int> p(n);
  for(auto&x:p) cin >> x, x--;
  string ans=s;
  for(int i=0; i<n; i++) ans[i]=s[p[i]];
  cout << ans << endl;
  return 0; 
}