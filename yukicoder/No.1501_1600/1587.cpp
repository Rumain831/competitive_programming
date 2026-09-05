#include<iostream>
using namespace std;

//Tags: grid, 構築
//Level: 2.5
//見つけた経緯を書き留めておく。
//とりあえず0~2n-1まで全部出る構築を考える
//0, 1, 2の個数をx, y, zとおくと、
//2(y+2z)=0+1+...+2n-1=n(2n-1) → y+2z=n^2-n/2
//またx+y+z=n^2である。n=2mとして、
//x+y+z=4m^2, y+2z=4m^2-m が得られる
//z=2m^2-km としてx, y, zをm, kで表し、k=1とすると
//x=2m^2, y=m, z=2m^2-mが出る。
//gridの半分が0, 2行に1回1が出る、残りが全部2として書いてみたらOKだった。

int main(void){
  int n; cin >> n;
  for(int i=0; i<n; i++){
    int r=n-1-i;
    for(int j=0; j<n; j++){
      if(j!=r) cout << (j<r?0:2);
      else cout << (i&1?1:0);
    }
    cout << endl;
  }
  return 0; 
}