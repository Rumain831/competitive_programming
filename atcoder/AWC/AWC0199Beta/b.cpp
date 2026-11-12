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
  int n, k; string s; cin >> n >> k >> s;
  auto [t, cnt]=rle(s);
  int ans=0;
  int m=t.size();
  for(int i=0; i<m; i++)if(t[i]=='.'){
    if(cnt[i]<k){
      cout << -1 << endl; return 0;
    }
    ans+=(cnt[i]+k-1)/k;
  }
  cout << ans << endl;
  return 0; 
}