#include<iostream>
#include<vector>
using namespace std;

//Tags: 全探索

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  int ans=1e9;
  for(int i=-100; i<=100; i++){
    int now=0;
    for(int j=0; j<n; j++) now+=(i-a[j])*(i-a[j]);
    ans=min(ans, now);
  }
  cout << ans << endl;
  return 0; 
}