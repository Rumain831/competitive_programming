#include<iostream>
using namespace std;

//Tags: 全探索, DFS

int match(string& s, string t){
  int n=s.size(), m=t.size();
  for(int i=0; i<n-m+1; i++){
    bool ok=true;
    for(int j=0; j<m; j++)if(t[j]!='.'&&s[i+j]!=t[j]){
      ok=false; break;
    }
    if(ok) return 1;
  }
  return 0;
}

int main(void){
  string s; cin >> s;
  int ans=0;
  auto dfs=[&](auto dfs, int step, string& x)->void {
    if(step==4) return;
    if(step) ans+=match(s, x);
    for(int i=0; i<26; i++){
      x+=(char)('a'+i);
      dfs(dfs, step+1, x);
      x.pop_back();
    }
    x+='.';
    dfs(dfs, step+1, x);
    x.pop_back();
  };
  string emp;
  dfs(dfs, 0, emp);
  cout << ans << endl;
  return 0; 
}