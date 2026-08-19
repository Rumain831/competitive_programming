#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n, m; cin >> n >> m;
  vector<vector<int>> ok(n, vector<int>(n));
  for(int i=0; i<m; i++){
    int x, y; cin >> x >> y; x--, y--;
    ok[x][y]=1, ok[y][x]=1;
  }
  int ans=-1;
  for(int i=1; i<(1<<n); i++){
    vector<int> p;
    for(int j=0; j<n; j++)if(i>>j&1) p.push_back(j);
    int m=p.size();
    bool f=true;
    for(int j=0; j<m-1; j++)for(int k=j+1; k<m; k++){
      if(!ok[p[j]][p[k]]){
        f=false; break;
      }
      if(!f) break;
    }
    if(f) ans=max(ans, m);
  }
  cout << ans << endl;
  return 0;
}