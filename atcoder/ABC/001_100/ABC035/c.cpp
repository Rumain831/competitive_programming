#include<iostream>
#include<vector>
using namespace std;

//Tags: imos法

int main(void){
  int n, q; cin >> n >> q;
  vector<int> imos(n+1);
  while(q--){
    int l, r; cin >> l >> r; l--;
    imos[l]++, imos[r]--;
  }
  for(int i=1; i<n; i++) imos[i]+=imos[i-1];
  for(int i=0; i<n; i++) cout << imos[i]%2; cout << endl;
  return 0;
}