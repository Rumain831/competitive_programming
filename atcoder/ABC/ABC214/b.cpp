#include<iostream>
using namespace std;

//Tags: 全探索

int main(void){
  int s, t; cin >> s >> t;
  int ans=0;
  for(int i=0; i<=s; i++)for(int j=0; i+j<=s; j++)for(int k=0; i+j+k<=s; k++){
    if(i*j*k<=t) ans++;
  }
  cout << ans << endl;
  return 0;
}