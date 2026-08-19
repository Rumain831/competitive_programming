#include<iostream>
using namespace std;

//場合分けして間違えるくらいなら全探索で蹴りをつけたい
int main(void){
  int h, w; cin >> h >> w;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    int ans=0;
    for(int x=0; x<h; x++)for(int y=0; y<w; y++){
      if(abs(i-x)+abs(j-y)==1) ans++;
    }
    cout << ans << (j==w-1?'\n':' ');
  }
  return 0; 
}