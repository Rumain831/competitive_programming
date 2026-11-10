#include<iostream>
using namespace std;

//Tags: 全探索

int main(void){
  int n; cin >> n;
  int ans=1e9;
  for(int i=1; i*i<=n; i++)for(int j=1; i*j<=n; j++){
    ans=min(ans, abs(i-j)+n-i*j);
  }
  cout << ans << endl;
  return 0;
}