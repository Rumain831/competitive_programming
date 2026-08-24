#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation
//Level: 1.5

int main(void){
  int n, m; cin >> n >> m;
  vector<int> card(n);
  for(int i=0; i<n; i++) card[i]=i+1;
  while(m--){
    int x; cin >> x; x--;
    for(int i=x; i>=1; i--){
      swap(card[i], card[i-1]);
    }
  }
  cout << card[0] << endl;
  return 0; 
}