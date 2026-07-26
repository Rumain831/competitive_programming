#include<iostream>
using namespace std;

//Tags: 文字列
//「1文字目同士の比較により、ずらし幅が一意に定まること」を利用してもよい

int main(void){
  string s, t; cin >> s >> t;
  int n=s.size();
  for(int i=0; i<26; i++){
    string kari;
    for(int j=0; j<n; j++){
      int now=s[j]-'a';
      now=(now+i)%26;
      kari+=(char)('a'+now);
    }
    if(kari==t){
      cout << "Yes" << endl; return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
