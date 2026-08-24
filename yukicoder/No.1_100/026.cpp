#include<iostream>
using namespace std;

//Tags: Simulation
//Level: 1

int main(void){
  int n, m; cin >> n >> m; n--;
  int cup[3]={};
  cup[n]++;
  for(int i=0; i<m; i++){
    int p, q; cin >> p >> q; p--, q--;
    swap(cup[p], cup[q]);
  }
  for(int i=0; i<3; i++){
    if(cup[i]){
      cout << i+1 << endl; return 0;
    }
  }
  return 0;
}