#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 貪欲法

int main(void){
  int n, k, x; cin >> n >> k >> x;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  sort(rbegin(a), rend(a));
  if(a[k-1]<x){
    cout << -1 << endl; return 0;
  }
  for(int i=0; i<k; i++) cout << a[i];
  return 0; 
}