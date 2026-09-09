#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: Simulation, 実装

int main(void){
  ll n, D; cin >> n >> D;
  vector<ll> h(n), adj(n);
  for(auto&x:h) cin >> x;
  int ans=0;
  vector<priority_queue<P, vector<P>, greater<P>>> pri(2);
  auto in=[&](int i){return (i>=0&&i<n);};
  for(int i=0; i<n; i++)if(h[i]<=0){
    ans++;
    adj[i]=1e9;
    if(in(i-1)) adj[i-1]++;
    if(in(i+1)) adj[i+1]++;
  }
  for(int i=0; i<n; i++)if(adj[i]==1||adj[i]==2) pri[adj[i]-1].emplace(h[i], i);
  for(int i=1; i<=n; i++){
    bool esc=true;
    vector<int> newv;
    vector<vector<P>> add(2);
    for(int j=0; j<2; j++){
      ll tar=D*i*(j+1);
      while(pri[j].size()){
        auto [hp, id]=pri[j].top();
        if(adj[id]!=j+1){
          pri[j].pop(); continue;
        }
        if(hp>tar) break;
        ans++;
        newv.push_back(id); pri[j].pop();
      }
    }
    map<int, int> mp;
    for(auto v:newv){
      adj[v]=1e9; esc=false;
      if(in(v-1)) adj[v-1]++, h[v-1]+=D*i, mp[v-1]=adj[v-1];
      if(in(v+1)) adj[v+1]++, h[v+1]+=D*i, mp[v+1]=adj[v+1];
    }
    for(auto [v, c]:mp){
      if(c==1||c==2) pri[c-1].emplace(h[v], v);
    }
    if(esc) break;
  }
  cout << ans << endl;
  return 0; 
}