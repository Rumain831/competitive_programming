#include<iostream>
using namespace std;

//Tags: Simulation
//https://codeforces.com/contest/977/problem/A

int main(void){
  int n, k; cin >> n >> k;
  for(int i=0; i<k; i++){
    if(n%10) n--;
    else n/=10;
  }
  cout << n << endl;
  return 0;
}