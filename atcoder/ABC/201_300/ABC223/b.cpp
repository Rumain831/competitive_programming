#include<iostream>
using namespace std;

//Tags: 全探索, 文字列

int main(void){
  string s; cin >> s;
  int n=s.size();
  string ans1=s, ans2=s;
  s+=s;
  for(int i=0; i<n; i++){
    string t=s.substr(i, n);
    ans1=min(ans1, t);
    ans2=max(ans2, t);
  }
  cout << ans1 << endl << ans2 << endl;
  return 0;
}