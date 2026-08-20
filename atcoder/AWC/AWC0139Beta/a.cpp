#include<iostream>
#include<vector>
using namespace std;

//Tags: 条件を満たすものの個数

int main(void){
  int n; cin >> n;
  vector<int> cnt(n+1);
  for(int i=0; i<n; i++){
    int a; cin >> a;
    cnt[a]++;
  }
  int ans=0;
  for(int i=1; i<=n; i++) ans+=(cnt[i]>cnt[0]);
  cout << ans << endl;
  return 0; 
}