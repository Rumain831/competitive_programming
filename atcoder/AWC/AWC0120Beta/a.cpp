#include<iostream>
#include<vector>
using namespace std;

//Tags: 条件を満たす要素の個数

int main(void){
  int n, k; cin >> n >> k;
  while(n--){
    int m, ans=0; cin >> m;
    while(m--){
      int s; cin >> s;
      ans+=(s>=k);
    }
    cout << ans << '\n';
  }
  return 0; 
}