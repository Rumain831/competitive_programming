#include<iostream>
#include<vector>
using namespace std;

//Tags: 実装
//Level: 1

int main(void){
  int n, m; cin >> n >> m;
  vector<int> cnt(m);
  vector<string> s(n);
  for(int i=0; i<n; i++){
    cin >> s[i];
    for(int j=0; j<m; j++)if(s[i][j]=='o') cnt[j]++;
  }
  int ans=0;
  for(int i=0; i<n; i++){
    int o=0;
    bool uni=true;
    for(int j=0; j<m; j++)if(s[i][j]=='o'){
      o++;
      if(cnt[j]>1) uni=false;
    }
    if(o&&uni) ans++;
  }
  cout << ans << endl;
  return 0; 
}