#include<iostream>
using namespace std;

//Tags: 文字列
//Level: 1

int main(void){
  string s; cin >> s;
  string ans;
  int n=s.size();
  for(int i=0; i<n; i++){
    int now=s[i]-'A';
    int ni=((now-i-1)%26+26)%26;
    ans+=(char)('A'+ni);
  }
  cout << ans << endl;
  return 0;
}