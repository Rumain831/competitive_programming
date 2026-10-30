#include<iostream>
using namespace std;

//Tags: Simulation

int main(void){
  int n, m; cin >> n >> m;
  string s; cin >> s;
  int erase[26][26]={};
  while(m--){
    char x, y; cin >> x >> y;
    erase[x-'A'][y-'A']++;
  }
  string ans;
  for(auto x:s){
    if(ans.size()){
      int top=ans.back()-'A', now=x-'A';
      if(erase[top][now]){
        ans.pop_back(); continue;
      }
      ans+=x;
    }
    else ans+=x;
  }
  cout << (ans.size()==0?"EMPTY":ans) << endl;
  return 0; 
}