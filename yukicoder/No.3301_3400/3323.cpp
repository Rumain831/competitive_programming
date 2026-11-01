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
  for(auto&x:s) cin >> x;
  string ans(m, 'G');
  vector<int> wait;
  for(int i=0; i<n; i++) wait.push_back(i);
  for(int i=0; i<m; i++){
    vector<int> old;
    swap(old, wait);
    int now=0;
    for(auto p:old){
      int x=(s[p][i]=='G'?0:(s[p][i]=='C'?1:2));
      now|=(1<<x);
    }
    int k=__builtin_popcount(now);
    if(k==3){
      cout << -1 << endl; return 0;
    }
    else if(k==1){
      ans[i]=(now==1?'P':(now==2?'G':'C'));
      cout << ans << endl; return 0;
    }
    else if(k==2){
      char win=(now==3?'G':(now==5?'P':'C'));
      char lose=(now==3?'C':(now==5?'G':'P'));
      ans[i]=win;
      for(auto p:old){
        if(s[p][i]==win) wait.push_back(p);
      }
    }
    else break;
  }
  if(wait.empty()) cout << ans << endl;
  else cout << -1 << endl;
  return 0; 
}