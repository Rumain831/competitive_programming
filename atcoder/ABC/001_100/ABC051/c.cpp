#include<iostream>
using namespace std;

//Tags: 構築, grid

string Go(int sx, int sy, int tx, int ty){
  string ans;
  while(sx!=tx){
    if(sx<tx) ans+='R', sx++;
    else ans+='L', sx--;
  }
  while(sy!=ty){
    if(sy<ty) ans+='U', sy++;
    else ans+='D', sy--;
  }
  return ans;
}

int main(void){
  int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
  string ans;
  ans+=Go(sx, sy, sx, ty)+Go(sx, ty, tx, ty);
  ans+=Go(tx, ty, tx, sy)+Go(tx, sy, sx, sy);
  ans+="L"+Go(sx-1, sy, sx-1, ty+1)+Go(sx-1, ty+1, tx, ty+1)+"D";
  ans+="R"+Go(tx+1, ty, tx+1, sy-1)+Go(tx+1, sy-1, sx, sy-1)+"U";
  cout << ans << endl;
  return 0; 
}