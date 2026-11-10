#include<iostream>
using namespace std;

//Tags: 文字列, 全探索

int main(void){
  string s; cin >> s;
  string t="WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
  int now=0;
  string mel[7]={"Do", "Re", "Mi", "Fa", "So", "La", "Si"};
  for(int i=0; i<20; i++){
    if(t[i]=='B') continue;
    if(t.substr(i, 20)==s){
      cout << mel[now] << endl; return 0;
    }
    now++;
  }
  return 0;
}