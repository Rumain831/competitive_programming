#include<iostream>
using namespace std;
using ll = long long;

//Tags: Simulation

int main(void){
  ll w, d; cin >> w >> d;
  for(ll i=d; i>=2; i--){
    ll minus=w/(i*i);
    w-=minus;
  }
  cout << w << endl;
  return 0; 
}