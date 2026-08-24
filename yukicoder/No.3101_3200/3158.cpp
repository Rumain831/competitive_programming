#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: DFS
//Level: 2

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<int> stamp(n), a(k);
  for(int i=0; i<k; i++){
    cin >> a[i]; a[i]--;
    stamp[a[i]]++;
  }
  vector t(n+1, vector<ll>(n+1));
  for(int i=0; i<n; i++)for(int j=0; j<n; j++) cin >> t[i][j];
  ll ans=1e18;
  auto dfs=[&](auto dfs, ll sum, int now, int step, set<int>& visited, vector<int>& path)->void {
    for(int i=0; i<n; i++){
      if(visited.count(i)) continue;
      visited.insert(i);
      path.push_back(i);
      sum+=t[now][i];
      if(visited.size()==m){
        if(stamp[i]){
          ans=min(ans, sum);
        }
        else{
          for(int j=0; j<k; j++){
            if(visited.count(a[j])) continue;
            else{
              ans=min(ans, sum+t[i][a[j]]);
            }
          }
        }
        sum-=t[now][i];
        visited.erase(i);
        path.pop_back();
        continue;
      }
      dfs(dfs, sum, i, step+1, visited, path);
      sum-=t[now][i];
      visited.erase(i);
      path.pop_back();
    }
    return;
  };
  set<int> vis;
  vector<int> q;
  dfs(dfs, 0, n, 0, vis, q);

  cout << ans << endl;
  return 0;
}