#include<iostream>
using namespace std;

//Tags: 文字列, 全探索

bool check(string s){
  int n=s.size();
  int cnt[26]={};
  for(auto x:s){
    int now=x-'a';
    cnt[now]++;
    if(cnt[now]>n-cnt[now]) return true;
  }
  return false;
}

int main(void){
  string s; cin >> s;
  int n=s.size();
  for(int i=0; i<n-1; i++){
    if(check(s.substr(i, 2))){
      cout << i+1 << ' ' << i+2 << endl; return 0;
    }
  }
  for(int i=0; i<n-2; i++){
    if(check(s.substr(i, 3))){
      cout << i+1 << ' ' << i+3 << endl; return 0;
    }
  }
  cout << -1 << ' ' << -1 << endl;
  return 0; 
}