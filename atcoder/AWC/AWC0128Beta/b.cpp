#include<iostream>
#include<vector>
using namespace std;

//Tags: 差分更新

int main(void){
  int n, k; cin >> n >> k;
  vector<char> w(n);
  for(auto&x:w) cin >> x;
  int ans=0, now=0;
  for(int i=0; i<k-1; i++) now+=(w[i]=='S');
  for(int i=k-1; i<n; i++){
    now+=(w[i]=='S');
    ans=max(ans, now);
    now-=(w[i-k+1]=='S');
  }
  cout << ans << endl;
  return 0; 
}