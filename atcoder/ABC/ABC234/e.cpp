#include<iostream>
using namespace std;
using ull = unsigned long long;

//Yags: 全探索, DFS, 整数

int main(void){
  ull x; cin >> x;
  ull inf=1111111111111111111, ans=inf;
  auto dfs=[&](auto dfs, ull now, ull d, int last){
    if(now>=x||now>=inf){
      ans=min(ans, now); return;
    }
    int nlast=last+d;
    if(nlast<0||nlast>=10) return;
    now=(now*10)+nlast;
    dfs(dfs, now, d, nlast);
    return;
  };
  for(int i=1; i<=9; i++){
    for(int j=-i; i+j<=9; j++){
      dfs(dfs, i, j, i);
    }
  }
  cout << ans << endl;
  return 0;
}