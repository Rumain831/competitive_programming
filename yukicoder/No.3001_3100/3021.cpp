#include<iostream>
using namespace std;

//Tags: 文字列, 実装

void solve(){
  string s; cin >> s;
  int n=s.size(), id=0;
  auto ok=[&](int i){
    if(i<0||i>=n) return false;
    if(s[i]=='-'||s[i]=='+') return false;
    return true;
  };
  while(id<n){
    int sg=1;
    if(s[id]=='-'||s[id]=='+'){
      if(s[id]=='-') sg*=-1;
      id++;
    }
    while(id<n){
      if(s[id]=='+'||s[id]=='-') break;
      if(s[id]=='?'){
        if(sg==1) s[id]='9';
        else{
          if(ok(id-1)&&ok(id+1)){
            s[id]='+'; break;
          }
          s[id]='1';
        }
      }
      id++;
    }
  }
  cout << s << endl;
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}