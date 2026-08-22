#include<iostream>
using namespace std;

//Tags: ランレングス圧縮, 文字列

int main(void){
  string s; cin >> s;
  string ans;
  int id=0, n=s.size();
  while(id<n){
    int c=0;
    char p=s[id];
    while(id<n&&s[id]==p) id++, c++;
    ans.push_back(p);
    ans+=to_string(c);
  }
  cout << ans << endl;
  return 0;
}