#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using P = pair<int, int>;
using PP = pair<bool, vector<int>>;

//Tags: DAG, 二分探索

int main(void){
  int n, m; cin >> n >> m;
  vector<int> w(m), k(m);
  vector<vector<int>> p(m);
  for(int i=0; i<m; i++){
    cin >> w[i] >> k[i];
    for(int j=0; j<k[i]; j++){
      int x; cin >> x; x--;
      p[i].push_back(x);
    }
  }
  vector<int> indeg(n);
  vector<vector<P>> to(n);
  auto judge=[&](int x){
    queue<int> qu;
    vector<int> ndeg=indeg;
    for(int i=0; i<n; i++)for(auto [v, w]:to[i]){
      if(w<=x) ndeg[v]--;
    }
    for(int i=0; i<n; i++)if(ndeg[i]==0) qu.push(i);
    vector<int> ans;
    while(qu.size()){
      int now=qu.front(); qu.pop();
      ans.push_back(now);
      for(auto [v, w]:to[now]){
        if(w>x){
          ndeg[v]--;
          if(ndeg[v]==0) qu.push(v);
        }
      }
    }
    if(ans.size()!=n) return PP(false, {});
    else return PP(true, ans);
  };
  vector<int> ans(m);
  for(int i=0; i<m; i++){
    for(int j=0; j<k[i]-1; j++){
      to[p[i][j]].emplace_back(p[i][j+1], w[i]);
      indeg[p[i][j+1]]++;
    }
    if(judge(0).first){
      ans[i]=0; continue;
    }
    int left=0, right=1e9+10;
    while(right-left>1){
      int mid=(left+right)/2;
      if(judge(mid).first) right=mid;
      else left=mid;
    }
    ans[i]=right;
  }
  for(auto p:ans) cout << p << ' '; cout << endl;
  auto q=judge(ans.back()).second;
  for(auto p:q) cout << p+1 << ' '; cout << endl;
  return 0; 
}