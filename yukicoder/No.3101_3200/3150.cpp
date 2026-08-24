#include<iostream>
using namespace std;

//Tags: bit演算
//Level: 1.5

int main(void){
  int a, b; cin >> a >> b;
  int ans=1;
  while(a||b){
    int aa=a%2, bb=b%2;
    if(aa&&!bb){
      cout << 0 << endl; return 0;
    }
    else if(aa&&bb) ans*=2ll;
    a/=2, b/=2;
  }
  cout << ans << endl;
  return 0;
}