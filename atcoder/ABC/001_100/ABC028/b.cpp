#include<iostream>
using namespace std;

int main(void){
  string s; cin >> s;
  int cnt[6]={};
  for(auto p:s) cnt[p-'A']++;
  for(int i=0; i<6; i++) cout << cnt[i] << (i==5?'\n': ' ');
  return 0; 
}