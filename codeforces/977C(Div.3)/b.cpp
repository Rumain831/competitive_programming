#include<iostream>
#include<map>
using namespace std;

//Tags: 全探索, 文字列
//https://codeforces.com/contest/977/problem/B

int main(void){
  int t; t=1;//cin >> t;
  for(int I=0; I<t; I++){
    int n; cin >> n;
    string s; cin >> s;
    map<string, int> cnt;
    for(int i=0; i<n-1; i++){
      cnt[s.substr(i, 2)]++;
    }
    int maxi=-1;
    string ans;
    for(auto p:cnt){
      if(p.second>maxi) ans=p.first, maxi=p.second;
    }
    cout << ans << endl;
  }
  return 0;
}