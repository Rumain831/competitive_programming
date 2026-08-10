#include<iostream>
using namespace std;

//Tags: Simulation

int main(void){
  int n; cin >> n;
  int rem=n, ans=0;
  while(n--){
    int f; cin >> f;
    rem=max(0, rem-f);
    if(rem) ans++, rem--;
  }
  cout << ans << endl;
  return 0; 
}