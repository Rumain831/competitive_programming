#include<iostream>
using namespace std;

//Tags: 整数
//Level: 2
//自然数x, y, z(x<y<z)に対し、x:y:z=1:2:3 が(x, y, z)が美しい組であることの必要十分条件 
// x+y<z+z=2z より x+y=z でないといけない
// x+z=2x+yがyの倍数より2xもyの倍数。2x<2yだから2x=y　でないといけない
// x+y=z, 2x=y より z=3x。逆にこのとき　y+z=5xとなり条件2を満たす。
// よって x:y:z = 1:2:3

int main(void){
  int a, b; cin >> a >> b;
  if(a>b) swap(a, b);
  if(b%3==0){
    if(b/3*2==a){
      cout << b/3 << endl; return 0;
    }
    if(b/3==a){
      cout << 2*a << endl; return 0;
    }
  }
  if(2*a==b){
    cout << 3*a << endl; return 0;
  }
  cout << -1 << endl;
  return 0; 
}