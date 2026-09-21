#include<iostream>
#include<vector>
using namespace std;

//Tags: grid

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector ans(n, string(m, '#'));
  while(k--){
    int r, c; cin >> r >> c; r--, c--;
    ans[r][c]='.';
  }
  for(auto p:ans) cout << p << endl;
  return 0; 
}