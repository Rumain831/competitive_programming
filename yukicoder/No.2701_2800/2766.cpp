#include<iostream>
using namespace std;
using ll = long long;
using P = pair<bool, string>;

//Tags: 再帰
//Level: 1.5

P dfs(ll n){
  if(n==1) return P(true, "");
  n--;
  bool ok=false;
  string ans;
  if(n%2==0){
    auto [f, s]=dfs(n/2);
    ok|=f;
    if(f) ans+=s+"A";
  }
  if(n%3==0){
    auto [f, s]=dfs(n/3);
    ok|=f;
    if(f) ans+=s+"B";
  }
  return P(ok, ans);
}

int main(void){
  ll n; cin >> n;
  cout << dfs(n).second << endl;
  return 0;
}