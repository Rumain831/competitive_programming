#include<iostream>
using namespace std;

//Tags: 全探索

int main(void){
  int k, s; cin >> k >> s;
  int ans=0;
  for(int x=0; x<=k; x++)for(int y=0; y<=k; y++){
    if(s-x-y>=0&&s-x-y<=k) ans++;
  }
  cout << ans << endl;
  return 0;
}