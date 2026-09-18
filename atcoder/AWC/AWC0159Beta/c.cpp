#include<iostream>
#include<vector>
using namespace std;

//Tags: bit全探索

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<int> sw(m);
  for(int i=0; i<m; i++){
    int c; cin >> c;
    while(c--){
      int x; cin >> x; x--;
      sw[i]+=(1<<x);
    }
  }
  int ans=1e9, mx=(1<<m);
  for(int i=0; i<mx; i++){
    int res=0;
    for(int j=0; j<m; j++)if(i>>j&1) res^=sw[j];
    if(__builtin_popcount(res)==k){
      ans=min(ans, __builtin_popcount(i));
    }
  }
  cout << (ans==1e9?-1:ans) << endl;
  return 0; 
}