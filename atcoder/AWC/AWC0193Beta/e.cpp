#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: ランレングス圧縮, imos法, 畳み込み

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
  int n, q; cin >> n >> q;
  vector<ll> s(n);
  for(auto&x:s) cin >> x;
  string t;
  for(int i=0; i<n-1; i++){
    if(s[i]==s[i+1]) t+='=';
    else t+=(s[i]<s[i+1]?'<':'>');
  }
  auto [tt, cnt]=rle(t);
  vector<ll> imos(n+2);
  int m=tt.size();
  for(int i=0; i<m-1; i++){
    if(tt[i]=='<'&&tt[i+1]=='>'){
      int a=cnt[i], b=cnt[i+1];
      for(int j=3; j<=a+2; j++){
        imos[j]++, imos[b+j]--;
      }
    }
  }
  for(int i=0; i<=n+1; i++) imos[i+1]+=imos[i];
  while(q--){
    int k; cin >> k;
    cout << imos[k] << '\n';
  }
  return 0; 
}