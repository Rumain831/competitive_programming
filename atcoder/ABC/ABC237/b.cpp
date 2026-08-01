#include<iostream>
#include<vector>
using namespace std;

//Tags: 配列

int main(void){
  int h, w; cin >> h >> w;
  vector a(h, vector<int>(w)), b(w, vector<int>(h));
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin >> a[i][j];
      b[j][i]=a[i][j];
    }
  }
  for(int i=0; i<w; i++)for(int j=0; j<h; j++){
    cout << b[i][j] << (j==h-1?'\n':' ');
  }
  return 0;
}