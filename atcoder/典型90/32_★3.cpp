#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 順列全探索
//解説URL: https://twitter.com/e869120/status/1390074137192767489

int main(void){
  int n; cin >> n;
  vector<int> p(n);
  vector a(n, vector<int>(n));
  for(auto&x:a)for(auto&y:x) cin >> y;
  for(int i=0; i<n; i++) p[i]=i;
  int m; cin >> m;
  vector ng(n, vector<int>(n));
  for(int i=0; i<m; i++){
    int x, y; cin >> x >> y; x--, y--;
    ng[x][y]=ng[y][x]=1;
  }
  int ans=1e9;
  do{
    bool ok=true;
    int now=0;
    for(int i=0; i<n; i++){
      now+=a[p[i]][i];
      if(i+1<n&&ng[p[i]][p[i+1]]){ok=false; break;}
    }
    if(ok) ans=min(ans, now);
  }while(next_permutation(p.begin(), p.end()));
  if(ans==1e9) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}