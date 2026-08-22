#include<iostream>
using namespace std;

//Tags: 全探索

int main(void){
  int n; cin >> n;
  string s, t="x"; cin >> s;
  t+=s+'x';
  int ans=0;
  for(int i=1; i<=n; i++)if(t[i]=='x'){
    if(t[i-1]==t[i+1]&&t[i-1]=='x') ans++;
  }
  cout << ans << endl;
  return 0; 
}