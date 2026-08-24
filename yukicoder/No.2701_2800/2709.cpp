#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 全探索
//Level: 2

int main(void){
  int n, p, q; cin >> n >> p >> q;
  vector<int> a(n);
  int x[4]={10, 9, 7, 5};
  vector pow(4, vector<int>{1});
  for(int i=0; i<4; i++){
    for(int j=1; j<=2e6; j++){
      int y=pow[i].back();
      y=(y*x[i])%p;
      pow[i].push_back(y);
    }
  }
  for(auto&x:a) cin >> x;
  sort(begin(a), end(a));
  int ans=0;
  auto dfs=[&](auto dfs, int step, int id, int now=0){
    if(step==4){
      if(now==q) ans++;
      return;
    }
    for(int i=id; i<n-3+step; i++){
      int nxt=(now+pow[step][a[i]])%p;
      dfs(dfs, step+1, i+1, nxt);
    }
    return;
  };
  dfs(dfs, 0, 0);
  cout << ans << endl;
  return 0; 
}