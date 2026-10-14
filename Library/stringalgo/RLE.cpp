#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

pair<string, vector<int>> rle(string s){ //ランレングス圧縮
  string ans;
  vector<int> cnt;
  int now=0, pre=0, n=s.size();
  while(now<n){
    char p=s[now];
    while(now<n&&s[now]==p) now++;
    ans.push_back(p);
    cnt.push_back(now-pre);
    pre=now;
  }
  return {ans, cnt};
}

int main(void){
  
  return 0; 
}