#include<iostream>
using namespace std;

//Tags: grid, 全探索
//Level: 1.5

int main(void){
  int h, w; cin >> h >> w;
  int a, b; cin >> a >> b; 
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  int p, q; cin >> p >> q; 
  int base=abs(p-a)+abs(q-b), ans=1e9;
  for(int i=r1; i<=r2; i++)for(int j=c1; j<=c2; j++){
    ans=min(ans, base+abs(a-i)+abs(b-j)+abs(p-i)+abs(q-j));
  }
  cout << ans << endl;
  return 0; 
}