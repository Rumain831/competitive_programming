#include<iostream>
using namespace std;

//Tags: Simulation
//Level: 1

int main(void){
  int mx=6000, now=0;
  bool imp=false;
  for(int i=0; i<7; i++){
    int t; cin >> t;
    if(imp||t==-1){
      imp=true;
      cout << -1 << endl; continue;
    }
    now+=t;
    if(now>mx) cout << -1 << endl;
    else cout << mx-now << endl;
  }
  return 0; 
}