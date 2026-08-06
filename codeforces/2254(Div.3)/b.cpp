#include<iostream>
#include<vector>
using namespace std;

//Tags: 全探索, ランレングス圧縮
//https://codeforces.com/contest/2254/problem/B

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

void solve(){
  int n; cin >> n;
  string s; cin >> s;
  auto [t, cnt]=rle(s);
  int m=t.size(), ans=m;
  for(int i=1; i<m-1; i++){
    if(cnt[i]>1) continue;
    int now=m; now--;
    if(t[i-1]==t[i+1]) now--;
    ans=min(ans, now);
  }
  cout << ans << endl;
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}