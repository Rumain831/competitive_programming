#include<iostream>
using namespace std;

//Tags: Simulation

int main(void){
  string s, ans; cin >> s;
  for(int i=0; i<s.size(); i++){
    if(s[i]!='B') ans.push_back(s[i]);
    else if(ans.size()) ans.pop_back();
  }
  cout << ans << endl;
  return 0; 
}