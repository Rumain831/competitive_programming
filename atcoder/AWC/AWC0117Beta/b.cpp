#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main(void){
  int n, q; cin >> n >> q;
  vector<ll> c(n+1), ans(n+1);
  for(int i=0; i<n; i++) cin >> c[i];
  c[n]=1e18;
  int id=0;
  while(q--){
    int t; cin >> t;
    if(t==1){
      ll v; cin >> v;
      while(v){
        if(ans[id]+v<=c[id]){
          ans[id]+=v; break;
        }
        else{
          ll d=c[id]-ans[id];
          ans[id++]+=d;
          v-=d;
        }
      }
    }
    else{
      int k; cin >> k; k--;
      cout << ans[k] << '\n';
    }
  }
  return 0; 
}