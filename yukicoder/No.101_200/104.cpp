#include<iostream>
using namespace std;

//Tags: Simulation
//Level: 1

int main(void){
  int ans=1;
  string s; cin >> s;
  for(auto p:s){
    if(p=='L') ans*=2;
    else ans=ans*2+1;
  }
  cout << ans << endl;
  return 0; 
}