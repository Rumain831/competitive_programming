#include<iostream>
using namespace std;
using P = pair<int, int>;

//Tags: 辞書順, 実装
//Level: 1.5

int main(void){
  string s, t; cin >> s >> t;
  if(s.size()!=t.size()){
    cout << (s.size()<t.size()?t:s) << endl;
    return 0;
  }
  int n=s.size();
  for(int i=0; i<n; i++){
    int ns=s[i]-'0', nt=t[i]-'0';
    if(P(ns, nt)==P(4, 7)||P(ns, nt)==P(7, 4)){
      cout << (ns>nt?t:s) << endl; return 0;
    }
    else if(ns!=nt){
      cout << (ns>nt?s:t) << endl; return 0;
    }
  }
  cout << s << endl;
  return 0; 
}