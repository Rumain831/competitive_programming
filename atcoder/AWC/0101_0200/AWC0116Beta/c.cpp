#include<iostream>
#include<vector>
using namespace std;

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
  int n, k; cin >> n >> k;
  vector<int> h(n);
  for(auto&x:h) cin >> x;
  string d;
  for(int i=0; i<n-1; i++){
    if(h[i]==h[i+1]) d+='=';
    else d+=(h[i]<h[i+1]?'<':'>');
  }
  int ans=0;
  auto [t, cnt]=rle(d);
  int m=t.size(), l=0;
  for(int i=0; i<m; i++){
    int mid, r;
    if(t[i]=='<') mid=l+cnt[i];
    else mid=l;
    if(t[i]=='>') r=mid+cnt[i];
    else if(i+1<m&&t[i+1]=='>') r=mid+cnt[i+1];
    else r=mid;
    int mx=h[mid], mi=min(h[l], h[r]);
    if(mx-mi>=k){
      ans=max(ans, r-l+1);
    }
    l+=cnt[i];
  }
  cout << ans << endl;
  return 0; 
}