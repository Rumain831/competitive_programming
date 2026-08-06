#include<iostream>
#include<vector>
#include<set>
using namespace std;
using ll = long long;

//Tags: 辞書順
//https://codeforces.com/contest/2254/problem/E
//sum(b)<=0なら不可能((b>=0のもの), (b<0のもの)の順に並べてaを定めても途中で0以下になる)
//そうでないなら構成可能
//0より大きいものの最小値xを取り、-xより大きいものの最小値yを取り、-x-yより大きいものの...を繰り返せばok

void solve(){
  int n; cin >> n;
  multiset<ll> val;
  ll sum=0;
  for(int i=0; i<n; i++){
    ll b; cin >> b;
    sum+=b;
    val.insert(b);
  }
  if(sum<=0){
    cout << -1 << '\n'; return;
  }
  sum=0;
  for(int i=0; i<n; i++){
    auto it=val.upper_bound(-sum);
    ll now=*it;
    sum+=now;
    cout << sum << ' ';
    val.erase(it);
  }
  cout << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}