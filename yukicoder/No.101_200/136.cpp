#include<iostream>
using namespace std;

//Tags: 整数
//Level: 2
//N未満の最大のNの約数が答え

int main(void){
  int n, k; cin >> n >> k;
  int ans=1;
  for(int g=1; g<n; g++){
    if(n%g) continue;
    ans=g;
  }
  cout << ans << endl;
  return 0; 
}