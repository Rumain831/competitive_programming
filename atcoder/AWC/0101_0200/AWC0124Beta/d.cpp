#include<iostream>
using namespace std;

//Tags: 貪欲, 考察で瞬殺

int main(void){
  int n, k; cin >> n >> k;
  int sumw=0, sums=0;
  for(int i=0; i<n; i++){
    int w, s; cin >> w >> s;
    sumw+=w, sums+=s;
  }
  if(sumw<k) cout << -1 << endl;
  else cout << sums << endl;
  return 0; 
}