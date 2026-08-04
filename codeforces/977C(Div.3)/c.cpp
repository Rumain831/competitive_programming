#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 尺取り法
//https://codeforces.com/contest/977/problem/C

int main(void){
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  sort(begin(a), end(a));
  if(k==0){
    cout << (a[0]==1?-1:1) << endl;
    return 0;
  }
  int id=0, cnt=0;
  while(id<n){
    int now=a[id];
    while(id<n&&a[id]==now) cnt++, id++;
    if(cnt==k){
      cout << now << endl; return 0;
    }
  }
  cout << -1 << endl;
  return 0; 
}