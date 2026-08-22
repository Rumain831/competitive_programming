#include<iostream>
#include<vector>
using namespace std;

//Tags: 全探索

int main(void){
  int n; cin >> n;
  int sum=0;
  vector<int> l(n);
  for(auto&x:l) cin >> x, sum+=x;
  int ans=1e9, now=0;
  for(int i=0; i<n-1; i++){
    now+=l[i];
    ans=min(ans, abs(sum-2*now));
  }
  cout << ans << endl;
  return 0; 
}