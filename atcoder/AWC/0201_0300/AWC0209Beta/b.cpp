#include<iostream>
using namespace std;

//Tags: 文字列

int main(void){
  int h, w; cin >> h >> w;
  int mi=1e9, ans;
  for(int i=0; i<h; i++){
    string s; cin >> s;
    int now=0;
    for(int j=0; j<w; j++){
      now+=s[j]-'0';
    }
    if(mi>now){
      mi=now, ans=i+1;
    }
  }
  cout << ans << endl;
  return 0; 
}