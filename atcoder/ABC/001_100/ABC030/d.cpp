#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: functional graph

int main(void){
  int n, a; cin >> n >> a; a--;
  string k; cin >> k;
  vector<int> b(n);
  for(int i=0; i<n; i++) cin >> b[i], b[i]--;
  vector<int> seen(n, -1);
  auto dfs=[&](auto dfs, int now, vector<int>& path, int cnt){
    path.push_back(now);
    seen[now]=cnt;
    now=b[now];
    if(seen[now]!=-1) return seen[now];
    return dfs(dfs, now, path, cnt+1);
  };
  vector<int> path;
  int cnt=dfs(dfs, a, path, 0);
  ll m=path.size();
  ll step=0;
  if(k.size()<=7){
    int p=stoi(k);
    if(p<m){
      cout << path[p]+1 << endl; return 0;
    }
  }
  m-=cnt;
  for(int i=0; i<k.size(); i++){
    int now=k[i]-'0';
    step*=10ll;
    step+=now; step%=m;
  }  
  step=(step-cnt+(ll)n*m)%m;
  cout << path[cnt+step]+1 << endl;
  return 0;
}