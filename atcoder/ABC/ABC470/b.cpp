#include<iostream>
using namespace std;

//Tags: 全探索

int cnt[101];

int main(void){
  int n; cin >> n;
  for(int i=0; i<n; i++){
    int c; cin >> c;
    cnt[c]++;
  }
  int ans=1e9;
  for(int i=1; i<=100; i++) ans=min(ans, n-cnt[i]);
  cout << ans << endl;
  return 0; 
}