#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 条件を満たすものの個数

int main(void){
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  sort(rbegin(a), rend(a));
  int tar=a[k-1], ans=0;
  for(auto p:a) ans+=(p>=tar);
  cout << ans << endl;
  return 0; 
}