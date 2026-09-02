#include<iostream>
using namespace std;

//Tags: Simulation, 考察で瞬殺

int main(void){
  int n; cin >> n;
  int mx=-1, ans;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    if(mx<x){
      mx=x; ans=i+1;
    }
  }
  cout << ans << endl;
  return 0; 
}