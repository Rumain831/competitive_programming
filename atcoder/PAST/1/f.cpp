#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 文字列, 実装

int main(void){
  string s; cin >> s;
  vector<string> ans;
  int first=-1, second;
  for(int i=0; i<s.size(); i++)if('A'<=s[i]&&s[i]<='Z'){
    if(first==-1){
      first=i; continue;
    }
    else{
      second=i;
      string t=s.substr(first, second-first+1);
      t[0]=(char)tolower(t[0]);
      t.back()=(char)tolower(t.back());
      ans.push_back(t);
      first=-1;
    }
  }
  sort(ans.begin(), ans.end());
  for(auto p:ans){
    p[0]=(char)toupper(p[0]);
    p.back()=(char)toupper(p.back());
    cout << p;
  }
  return 0;
}