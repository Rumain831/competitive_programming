#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation
//Level: 1

int main(void){
  int n; cin >> n;
  vector<int> t(n);
  for(auto&x:t) cin >> x;
  int ok=0, ans=0;
  for(int i=0; i<n; i++){
    int s; cin >> s;
    if(ok<=s){
      ans++, ok=s+t[i];
    }
  }
  cout << ans << endl;
  return 0; 
}