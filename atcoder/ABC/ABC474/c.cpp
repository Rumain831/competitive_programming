#include<iostream>
#include<vector>
#include<map>
using namespace std;

//Tags: Simulation

int main(void){
  int n, q; cin >> n >> q;
  vector<int> p(n);
  for(auto&x:p) cin >> x;
  map<int, int> pre, aft;
  int pv=0;
  for(int i=0; i<n; i++){
    pre[p[i]]=pv;
    aft[pv]=p[i];
    pv=p[i];
  }
  pre[n+1]=pv, aft[pv]=n+1;
  while(q--){
    int a; cin >> a;
    int x=pre[a], y=aft[a], la=pre[n+1];
    if(la==a) continue;
    //x a y
    pre[y]=x, aft[x]=y;
    //la a n+1
    pre[a]=la, aft[la]=a;
    pre[n+1]=a, aft[a]=n+1;
  }
  vector<int> ans;
  int now=0;
  while(now!=n+1){
    if(now) ans.push_back(now);
    now=aft[now];
  }
  for(auto p:ans) cout << p << ' ';
  return 0; 
}