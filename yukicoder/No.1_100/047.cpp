#include<iostream>
using namespace std;

//Tags: n進数
//Level: 1.5
//2^d<=n を満たすギリギリまで叩いだ後、(n>2^dなら)n-2^d枚をポケットに入れて叩く。

int main(void){
  int n; cin >> n;
  int ans=0, c=0;
  while(n>1){
    if(n&1) c++;
    ans++, n/=2;
  }
  cout << ans+(c>0) << endl;
  return 0; 
}