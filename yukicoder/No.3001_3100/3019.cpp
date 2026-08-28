#include<iostream>
using namespace std;

//Tags: 文字列, 場合分け
//Level: 1

int main(void){
  string s, t; cin >> s >> t;
  int n=s.size(), m=t.size();
  if(m!=n&&m!=n-1){
    cout << "?" << endl; return 0;
  }
  for(int i=0; i<n; i++){
    cout << s[i];
    if(i<m) cout << t[i];
  }
  return 0; 
}