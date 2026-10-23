#include<iostream>
using namespace std;

//Tags: 文字列

int main(void){
  int hole[10]={1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
  int ans1=1, ans2=2;
  string s; cin >> s;
  for(auto p:s){
    int now=p-'0';
    ans1+=2+hole[now];
    ans2+=2*hole[now]+1;
  }
  cout << min(ans1, ans2) << endl;
  return 0; 
}