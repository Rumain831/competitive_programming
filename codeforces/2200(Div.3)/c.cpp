#include<iostream>
using namespace std;

//Tags: 文字列, 括弧列

void solve(){
  int n; cin >> n;
  string s, t; cin >> s; 
  for(auto p:s){
    if(p=='*') continue;
    if(t.size()&&t.back()==p) t.pop_back();
    else t+=p;
  }
  cout << (t.empty()?"YES":"NO") << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}