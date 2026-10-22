#include<iostream>
#include<vector>
using namespace std;

//Tags: 文字列, ランレングス圧縮

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
  int n; string s; cin >> n >> s;
  auto [t, cnt]=rle(s);
  int ans=0;
  for(auto p:t) ans+=(p=='#');
  cout << ans << endl;
  return 0; 
}