#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 全探索, XOR基底

bool judge(vector<ll>& base, ll tar){
  for(auto p:base){
    tar=min(tar, tar^p);
  }
  return tar==0;
}

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> v(n), w(n), t(m);
  for(int i=0; i<n; i++) cin >> v[i] >> w[i];
  for(auto&x:t) cin >> x;
  int mx=(1<<n), ans=0;
  for(int i=0; i<mx; i++){
    vector<ll> use;
    for(int j=0; j<n; j++){
      if(i>>j&1) use.push_back(v[j]);
      else use.push_back(w[j]);
    }
    vector<ll> base;
    for(int j=0; j<n; j++){
      ll now=use[j];
      for(auto p:base){
        now=min(now, p^now);
      }
      if(now) base.push_back(now);
    }
    bool add=true;
    for(int j=0; j<m; j++){
      if(!judge(base, t[j])){
        add=false; break;
      }
    }
    if(add) ans++; 
  }
  cout << ans << endl;
  return 0; 
}