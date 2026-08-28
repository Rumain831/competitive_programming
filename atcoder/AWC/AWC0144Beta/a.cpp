#include<iostream>
using namespace std;

//Tags: 条件を満たすものの個数

int main(void){
  int n, m; cin >> n >> m;
  int mi=1e9;
  while(n--){
    int l; cin >> l;
    mi=min(l, mi);
  }
  int ans=0;
  while(m--){
    int s; cin >> s;
    ans+=(mi>=s);
  }
  cout << ans << endl;
  return 0; 
}