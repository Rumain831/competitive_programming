#include<iostream>
using namespace std;

//Tags: 文字列

int main(void){
  string w; cin >> w;
  int cnt[26]={};
  for(auto x:w) cnt[x-'a']++;
  for(int i=0; i<26; i++)if(cnt[i]%2){
     cout << "No" << endl; return 0;
  }
  cout << "Yes" << endl;
  return 0; 
}