#include<iostream>
using namespace std;

//Tags: 文字列

int main(void){
  int n; string s; cin >> n >> s;
  string t="b";
  int ans=0, m=t.size();
  while(n>m){
    char left="acb"[ans%3], right="cab"[ans%3];
    t=left+t+right, m+=2, ans++;
  }
  cout << (s==t?ans:-1) << endl;
  return 0;
}