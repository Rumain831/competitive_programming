#include<iostream>
using namespace std;

//Tags: 構築, grid
//Level: 1.5

int main(void){
  int n; cin >> n;
  for(int i=0; i<n; i++)for(int j=0; j<n; j++){
    cout << (i+j)%n+1 << (j==n-1?'\n':' ');
  }
  return 0; 
}