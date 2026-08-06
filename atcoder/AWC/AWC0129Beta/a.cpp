#include<iostream>
#include<vector>
using namespace std;

//Tags: 文字列

int main(void){
  int n; cin >> n;
  vector<string> sen, san;
  while(n--){
    string s, t; cin >> s >> t;
    if(t=="student"||t=="other") san.emplace_back(s+" san");
    else sen.emplace_back(s+" sensei");
  }
  for(auto p:sen) cout << p << '\n';
  for(auto p:san) cout << p << '\n';
  return 0; 
}