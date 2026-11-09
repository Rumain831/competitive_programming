#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 尺取り法, 累積

int main(void){
  int n; cin >> n;
  vector<int> c(n);
  for(auto&x:c) cin >> x, x--;
  vector mini(n+1, vector<int>(7, n));
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<7; j++) mini[i][j]=mini[i+1][j];
    mini[i][c[i]]=i;
  }
  ll ans=0;
  for(int i=0; i<n; i++){
    int mx=-1;
    for(int j=0; j<7; j++) mx=max(mx, mini[i][j]);
    ans+=n-mx;
  }
  cout << ans << endl;
  return 0; 
}