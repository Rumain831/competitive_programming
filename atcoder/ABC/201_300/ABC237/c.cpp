#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 回文

int main(void){
  string s; cin >> s;
  int cnt[2]={};
  for(int i=0; i<2; i++){
    while(s.size()&&s.back()=='a') s.pop_back(), cnt[1-i]++;
    reverse(begin(s), end(s));
  }
  string t=s;
  reverse(begin(t), end(t));
  cout << (s==t&&cnt[0]<=cnt[1]?"Yes":"No") << endl;
  return 0; 
}