#include<iostream>
#include<vector>
using namespace std;

//Tags: 貪欲法, じゃんけん
//Level: 1.5
//手が1種類しかないなら勝ちの手を出して後は適当に。
//手が3種類あるなら誰かに負けるので-1。
//手が2種類なら負けない手を出して、あいこになる人たちだけ残す
//最終的に全員に勝てばOK。あいこが残れば-1。

int main(void){
  int n, m; cin >> n >> m;
  vector<string> s(n);
  vector<int> rem;
  for(int i=0; i<n; i++){
    cin >> s[i];
    rem.push_back(i);
  }
  string ans(m, 'G');
  auto f=[&](int a[3]){
    if(a[0]==0) return 'C';
    if(a[1]==0) return 'P';
    if(a[2]==0) return 'G';
    return '!';
  };
  for(int i=0; i<m; i++){
    vector<int> old;
    swap(old, rem);
    int cnt[3]={};
    for(auto p:old){
      if(s[p][i]=='G') cnt[0]++;
      else if(s[p][i]=='C') cnt[1]++;
      else cnt[2]++;
    }
    char x=f(cnt);
    if(x=='!'){
      cout << -1 << endl; return 0;
    }
    ans[i]=x;
    for(auto p:old)if(s[p][i]==x) rem.push_back(p);
    if(rem.empty()) break;
  }
  if(rem.size()) cout << -1 << endl;
  else cout << ans << endl;
  return 0; 
}