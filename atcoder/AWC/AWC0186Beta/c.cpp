#include<iostream>
using namespace std;

//Tags: 文字列

int main(void){
  int n, m, k; cin >> n >> m >> k;
  string s; cin >> s;
  int ans=0, now=0;
  for(int i=0; i<m-1; i++) now+=(s[i]=='1');
  for(int i=m-1; i<n; i++){
    now+=(s[i]=='1');
    if(now<k) ans++;
    now-=(s[i-m+1]=='1');
  }
  cout << ans << endl;
  return 0; 
}