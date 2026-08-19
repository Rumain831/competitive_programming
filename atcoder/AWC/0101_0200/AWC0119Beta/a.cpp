#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation

int main(void){
  int n; cin >> n;
  vector<int> cnt(101);
  int kind=0, sum=0;
  for(int i=0; i<n; i++){
    int s; cin >> s;
    if(cnt[s]==0) kind++, sum+=s;
    cnt[s]++;
  }
  cout << kind << ' ' << sum << endl;
  return 0; 
}