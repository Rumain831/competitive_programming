#include<iostream>
using namespace std;

//Tags: Simulation
//Level: 1.5

int main(void){
  int n; cin >> n;
  int ans=1;
  n=(n%2?3*n+1:n/2);
  while(n!=1){
    n=(n%2?3*n+1:n/2);
    ans++;
  }
  cout << ans << endl;
  return 0;
}