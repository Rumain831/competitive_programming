#include<iostream>
#include<vector>
using namespace std;

//Tags: 実装
//Level: 1.5

int main(void){
  string s; cin >> s;
  vector<int> val, op;
  int id=0, n=s.size();
  while(id<n){
    int x=0;
    while(id<n){
      if(s[id]=='*'||s[id]=='+') break;
      int now=s[id]-'0';
      x=(x*10)+now;
      id++;
    }
    val.push_back(x);
    if(id==n) break;
    op.push_back(s[id]=='*');
    id++;
  }
  int m=op.size(), ans=val[0];
  for(int i=0; i<m; i++){
    if(op[i]) ans+=val[i+1];
    else ans*=val[i+1];
  }
  cout << ans << endl;
  return 0; 
}