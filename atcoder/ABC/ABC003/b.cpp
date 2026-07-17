#include<iostream>
using namespace std;
using ll = long long;

int main(void){
  string s, t; cin >> s >> t;
  string at="atcoder";
  int n=s.size();
  for(int i=0; i<n; i++){
    if(s[i]==t[i]) continue;
    if(s[i]=='@'){
      if(at.find(t[i])==string::npos){
        cout << "You will lose" << endl; return 0;
      }
    }
    else{
      if(at.find(s[i])==string::npos||t[i]!='@'){
        cout << "You will lose" << endl; return 0;
      }
    }
  }
  cout << "You can win" << endl;
  return 0;
}