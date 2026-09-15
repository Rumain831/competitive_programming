#include<iostream>
using namespace std;

//Tags: 文字列

int main(void){
  int n; cin >> n;
  string t="tanabata";
  int mx=0, ans=1, m=t.size();
  for(int i=0; i<n; i++){
    string s; cin >> s;
    int now=0;
    for(int j=0; j+m-1<s.size(); j++){
      if(s.substr(j, m)==t) now++;
    }
    if(mx<now){
      mx=now;
      ans=i+1;
    }
  }
  cout << ans << endl;
  return 0; 
}