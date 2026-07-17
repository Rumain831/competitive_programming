#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//一般の連結な単純無向グラフを考える前に、グラフが木になっている場合を考えてみる
//（木で解けないのに、一般のグラフで解けるわけがない）
//木の場合、頂点1を根としてAiを深さをすればいいことに気付く。
//一般の連結な単純無向グラフでも全域木は取れる。全域木といえばDFS木やBFS木(ABC251F)。
//で、本問の場合は(頂点1を根とする)DFS木を取って深さを出せばOK。
void solve(){
  int n, m; cin >> n >> m;
  vector<vector<int>> to(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v); swap(u, v);
    to[u].push_back(v);
  }
  vector<int> ans(n, -1);
  auto dfs=[&](auto dfs, int now, int par=-1, int h=0)->void {
    ans[now]=h++;
    for(auto p:to[now])if(p!=par&&ans[p]==-1){
      dfs(dfs, p, now, h);
    }
    h--;
  };
  dfs(dfs, 0);
  for(auto p:ans) cout << p << ' '; cout << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}
