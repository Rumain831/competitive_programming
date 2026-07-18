#include<iostream>
using namespace std;

int main(void){
  string s; cin >> s;
  string ans;
  for(int i=0; i<s.size(); i++){
    if(i==0) ans+=(char)toupper(s[i]);
    else ans+=(char)tolower(s[i]);
  }
  cout << ans << endl;
  return 0;
}