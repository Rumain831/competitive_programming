#include<iostream>
#include<vector>
using namespace std;

//Tags: functional graph

int main(void){
  int n, q; cin >> n >> q;
  vector<int> to(n);
  for(auto&x:to) cin >> x, x--;
  vector<int> seen(n), ans(n);
  auto dfs=[&](auto dfs, int now, vector<int>& path){
    path.push_back(now);
    seen[now]=1;
    int nxt=to[now];
    if(seen[nxt]==2){
      int c=ans[nxt];
      while(path.size()){
        c++;
        ans[path.back()]=c;
        seen[path.back()]=2;
        path.pop_back();
      }
      return true;
    }
    else if(seen[nxt]==1){
      int id=now;
      vector<int> roop;
      while(1){
        roop.push_back(id);
        seen[id]=2;
        path.pop_back();
        if(id==nxt) break;
        id=path.back();
      }
      int c=roop.size();
      for(auto p:roop) ans[p]=c;
      while(path.size()){
        c++;
        ans[path.back()]=c;
        seen[path.back()]=2;
        path.pop_back();
      }
      return true;
    }
    else{
      if(dfs(dfs, nxt, path)) return true;
    }
    return false;
  };
  for(int i=0; i<n; i++){
    if(seen[i]) continue;
    vector<int> emp;
    dfs(dfs, i, emp);
  }
  while(q--){
    int s; cin >> s; s--;
    cout << ans[s] << '\n';
  }
  return 0; 
}