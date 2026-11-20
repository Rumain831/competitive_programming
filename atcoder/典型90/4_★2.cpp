#include<iostream>
#include<vector>
using namespace std;

//Tags: grid
//解説URL: https://twitter.com/e869120/status/1378115289649348611

int main(void){
  int h, w;
  cin >> h >> w;
  vector a(h, vector<int>(w));
  vector<int> col(w), row(h);
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin >> a[i][j];
      col[j]+=a[i][j], row[i]+=a[i][j];
    }
  }
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    cout << col[j]+row[i]-a[i][j] << (j==w-1?'\n':' ');
  }
  return 0;
}