#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using P = pair<int, int>;

void solve(){
  string s; cin >> s;
  int n=s.size(), lim=(n+1)/2;
  if(s.size()==1){
    cout << "Yes" << '\n' << s << '\n';
    return;
  }
  string ans(n, '?');
  vector<int> cnt(26);
  for(auto p:s) cnt[p-'a']++;
  priority_queue<P> pri;
  for(int i=0; i<26; i++){
    if(cnt[i]>lim){
      cout << "No" << '\n'; return;
    }
    if(cnt[i]) pri.emplace(cnt[i], i);
  }
  cout << "Yes" << '\n';
  int id=0;
  while(pri.size()){
    auto [c, si]=pri.top(); pri.pop();
    while(c--){
      ans[id]=(char)('a'+si);
      id+=2;
      if(id>=n) id=1;
    }
  }
  cout << ans << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}