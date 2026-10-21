#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: ゲーム, 考察で瞬殺

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<int> b(m);
  int mx=-1;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    mx=max(mx, a);
  }
  for(auto&x:b) cin >> x;
  int ans=0;
  for(int i=0; i<m; i++){
    if(mx<b[i]) break;
    else ans++;
  }
  cout << ans << endl;
  return 0; 
}