#include<iostream>
using namespace std;

//Tags: 場合分け

int main(void){
  int x, y, l; cin >> x >> y >> l;
  int ans=(abs(x)+l-1)/l+(abs(y)+l-1)/l;
  if(x==0||y==0){
    if(x==0&&y==0) cout << 0 << endl;
    else if(x==0) cout << ans+2*(y<0) << endl;
    else cout << ans+1 << endl;
    return 0;
  }
  cout << ans+(y>0?1:2) << endl;
  return 0; 
}