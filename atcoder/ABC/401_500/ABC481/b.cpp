#include<iostream>
#include<vector>
using namespace std;

//Tags: 数え上げ, 幾何

int main(void){
  int n, k; cin >> n >> k;
  vector<int> a(n);
  int ans=0;
  for(auto&x:a) cin >> x, ans+=(x==k);
  for(int i=0; i<n-1; i++){
    if((k-a[i])*(k-a[i+1])<0) ans++;
  }
  cout << ans << endl;
  return 0; 
}