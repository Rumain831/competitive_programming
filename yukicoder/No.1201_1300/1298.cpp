#include<iostream>
using namespace std;

//Tags: 構築, XOR
//Level: 1.5

int main(void){
  int n; cin >> n;
  if(__builtin_popcount(n)==1){
    printf("-1 -1 -1\n"); return 0;
  }
  int ans[3]={};
  int c=0, x=0;
  while(n){
    if(n&1){
      ans[c]+=(1<<x);
      ans[(c+1)%3]+=(1<<x);
      c=(c+1)%3;
    }
    n/=2; x++;
  }
  cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
  return 0; 
}