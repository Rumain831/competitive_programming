#include<iostream>
using namespace std;

//Tags: 整数

int main(void){
  string s; cin >> s;
  int ans=0;
  for(int i=0; i<3; i++){
    ans+=stoi(s);
    s=s.substr(1, 2)+s[0];
  }
  cout << ans << endl;
  return 0;
}