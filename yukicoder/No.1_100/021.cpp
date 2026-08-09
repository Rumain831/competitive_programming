#include<iostream>
using namespace std;

//Tags: 最適化

int main(void){
  int n, k; cin >> n >> k;
  int mini=1e9, maxi=-1;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    mini=min(mini, a);
    maxi=max(maxi, a);
  }
  cout << maxi-mini << endl;
  return 0;
}