#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using P = pair<int, int>;

//Tags: BFS, bit演算

int tonum(string s){
  int ans=0, n=s.size();
  for(int i=0; i<n; i++){
    int c=s[i]-'A';
    ans+=c*(1<<(n-1-i));
  }
  return ans;
}

int main(void){
  int n; cin >> n;
  string s, t; cin >> s >> t;
  int ns=tonum(s), nt=tonum(t);
  int mx=(1<<n), erase=(1<<(n-1));
  vector<int> g, mul;
  for(int i=1; i<n; i++)if(n%i==0){
    g.push_back(i);
    int t=n/i, x=1; t--;
    while(t--){
      x<<=i;
      x++;
    }
    mul.push_back(x);
  }
  int m=g.size();
  vector<int> dist(mx, 1e9);
  queue<P> bfs;
  bfs.emplace(0, ns);
  dist[ns]=0;
  auto push=[&](int nxt, int d){
    if(dist[nxt]>d){
      dist[nxt]=d;
      bfs.emplace(d, nxt);
    }
  };
  while(bfs.size()){
    auto [d, now]=bfs.front(); bfs.pop();
    if(dist[now]!=d) continue;
    {
      int nxt=now, top=(nxt>>(n-1)&1);
      if(top) nxt-=erase;
      nxt<<=1, nxt+=top;
      push(nxt, d+1);
    }
    {
      int nxt=now, bot=(nxt&1);
      nxt>>=1;
      nxt+=bot*erase;
      push(nxt, d+1);
    }
    for(int i=0; i<m; i++){
      int x=n-g[i];
      int nxt=now; nxt>>=x;
      nxt*=mul[i];
      push(nxt, d+1);
    }
  }
  cout << (dist[nt]==1e9?-1:dist[nt]) << endl;
  return 0; 
}