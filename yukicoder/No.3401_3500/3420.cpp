#include<iostream>
#include<vector>
using namespace std;

//Tags: grid, 文字列, Simulation
//Level: 1

int main(void){
  int n, w, h; cin >> n >> w >> h;
  string s; cin >> s;
  vector ans(h, string(w, 'x'));
  s+='l';
  int j=0, c=0;
  for(auto p:s){
    if(p=='o') c++;
    else{
      for(int i=0; i<c; i++) ans[h-1-i][j]='o';
      j++, c=0;
    }
  }
  for(auto p:ans) cout << p << endl;
  return 0; 
}