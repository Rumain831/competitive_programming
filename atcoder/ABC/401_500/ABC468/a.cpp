#include<iostream>
#include<vector>
using namespace std;

//Tags: 条件を満たすものの個数

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  int ans=0;
  for(int i=1; i<n-1; i++) ans+=(a[i-1]<a[i]&&a[i]>a[i+1]);
  cout << ans << endl;
  return 0; 
}