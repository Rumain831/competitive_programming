#include<iostream>
#include<vector>
using namespace std;

//Tags: 貪欲法
//Level: 1

int main(void){
  int n; cin >> n;
  vector<int> cnt(n+1);
  for(int i=0; i<n; i++){
    int a; cin >> a; cnt[a]++;
  }
  int ans=0;
  for(int i=1; i<=n; i++) ans+=cnt[i]/2;
  cout << ans << endl;
  return 0; 
}