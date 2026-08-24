#include<iostream>
using namespace std;

//Tags: 文字列
//Level: 1

int cnt[26];
int main(void){
  int n; cin >> n;
  string s; cin >> s;
  for(auto p:s) cnt[p-'A']++;
  for(int i=0; i<26; i++) cout << cnt[i]; cout << endl;
  return 0; 
}