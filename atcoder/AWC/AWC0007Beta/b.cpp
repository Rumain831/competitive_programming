#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(void){
  int n, k; cin >> n >> k;
  vector cnt(n, vector<int>(n));
  map<string, vector<int>> mp;
  for(int i=0; i<n; i++){
    int m; cin >> m;
    while(m--){
      string w; cin >> w;
      mp[w].push_back(i);
    }
  }
  for(auto& [w, vec]:mp){
    int kk=vec.size();
    for(int i=0; i<kk-1; i++)for(int j=i+1; j<kk; j++){
      cnt[vec[i]][vec[j]]++;
    }
  }
  int ans=0;
  for(int i=0; i<n-1; i++)for(int j=i+1; j<n; j++)if(cnt[i][j]>=k) ans++;
  cout << ans << endl;
  return 0;
}