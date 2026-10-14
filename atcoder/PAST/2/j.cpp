#include<iostream>
#include<algorithm>
using namespace std;

//Tags: 構文解析, 再帰

int n, pos=0;
string s;

string dfs(){
  string t;
  while(pos<n){
    char c=s[pos++];
    if(c=='('){
      t+=dfs();
    }
    else if(c==')'){
      string p=t;
      reverse(begin(p), end(p));
      return t+p;
    }
    else t+=c;
  }
  return t;
}

int main(void){
  cin >> s;
  n=s.size();
  cout << dfs() << endl;
  return 0; 
}