#include<iostream>
using namespace std;

int main(void){
  int n, m; cin >> n >> m;
  // x+y+z=n, 2x+3y+4z=m
  for(int z=0; z<=n&&4*z<=m; z++){
    int p=n-z, q=m-4*z;
    //2x+2y=2p, 2x+3y=q
    int y=q-2*p, x=p-y;
    if(x>=0&&y>=0){
      cout << x << ' ' << y << ' ' << z << endl;
      return 0;
    } 
  }
  cout << -1 << ' ' << -1 << ' ' << -1 << endl;
  return 0;
}