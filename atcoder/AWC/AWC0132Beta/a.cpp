#include<iostream>
using namespace std;

//Tags: Simulation

int main(void){
  int n, p; cin >> n >> p;
  int ans=0;
  for(int i=0; i<n; i++){
    int h; cin >> h;
    if(p>=h) ans++, p-=h;
    else p+=h;
  }
  cout << ans << endl;
  return 0; 
}