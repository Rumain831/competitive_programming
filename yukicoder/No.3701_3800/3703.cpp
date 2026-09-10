#include<iostream>
#include<vector>
using namespace std;

//Tags: 文字列, 回転
//Level: 1.5

int main(void){
  int h, w; cin >> h >> w;
  vector<string> s(h), ans(w, string(h, '.'));
  for(auto&x:s) cin >> x;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    int ni=j, nj=h-1-i;
    ans[ni][nj]=s[i][j];
  }
  for(auto&x:ans) cout << x << endl;
  return 0; 
}