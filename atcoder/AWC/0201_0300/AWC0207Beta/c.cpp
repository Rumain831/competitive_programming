#include<iostream>
#include<map>
using namespace std;

//Tags: 貪欲法

int main(void){
  int n, m; cin >> n >> m;
  map<int, int> cnt;
  for(int i=0; i<n; i++)for(int j=0; j<m; j++){
    int a; cin >> a;
    cnt[a]++;
  }
  int mx=0;
  for(auto [_, x]:cnt) mx=max(mx, x);
  cout << m*n-mx << endl;
  return 0; 
}