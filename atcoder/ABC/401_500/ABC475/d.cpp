#include<iostream>
#include<vector>
using namespace std;

//Tags: 素数, 全探索

int main(void){
  string s; cin >> s;
  int nn=1e7;
  vector<int> yakusu(nn+1, -1), prime;
  for(int i=2; i<=nn; i++){
    if(yakusu[i]!=-1) continue;
    int copy=i;
    prime.push_back(i);
    while(copy<=nn){
      if(yakusu[copy]==-1) yakusu[copy]=i;
      copy+=i;
    }
  }
  int n=s.size();
  auto dfs=[&](auto dfs, int step, string& t, vector<int>& usednum, vector<int>& tab){
    if(step==n){
      if(t[0]=='0') return -1;
      int now=stoi(t);
      if(yakusu[now]==now) return now;
      else return -1;
    }
    int now=s[step]-'a';
    if(tab[now]==-1)for(int i=0; i<10; i++){
      if(usednum[i]) continue;
      t[step]=(char)('0'+i);
      usednum[i]=1;
      tab[now]=i;
      int nxt=dfs(dfs, step+1, t, usednum, tab);
      if(nxt!=-1) return nxt;
      usednum[i]=0;
      tab[now]=-1;
    }
    else{
      t[step]=(char)('0'+tab[now]);
      int nxt=dfs(dfs, step+1, t, usednum, tab);
      if(nxt!=-1) return nxt;
    }
    return -1;
  };
  string ans(n, '.');
  vector<int> num(10), al(26, -1); 
  cout << dfs(dfs, 0, ans, num, al) << endl;
  return 0; 
}