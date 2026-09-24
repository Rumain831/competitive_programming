#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: bit全探索, 区間, 実装

int main(void){
  int t, n, k, m; cin >> t >> n >> k >> m;
  vector<int> l(n), r(n);
  for(int i=0; i<n; i++) cin >> l[i] >> r[i];
  int mx=(1<<n), ans=1e9;
  for(int i=0; i<mx; i++){
    vector<int> imos(t+2);
    for(int j=0; j<n; j++)if(i>>j&1) imos[l[j]]++, imos[r[j]]--;
    for(int j=0; j<t+1; j++) imos[j+1]+=imos[j];
    vector<P> seg;
    {
      int l=0, r=0;
      while(l<t){
        if(imos[l]){
          l++; continue;
        }
        r=l;
        while(r<t&&imos[r]==0) r++;
        seg.emplace_back(l, r);
        l=r;
      }
    }
    int lim=m;
    bool ok=true;
    for(auto [l, r]:seg){
      if(lim<l){
        ok=false; break;
      }
      int len=r-l;
      if(len>=k){
        lim=max(lim, r+m); continue;
      }
      if(lim<r){
        ok=false; break;
      }
    }
    if(lim<t) ok=false; 
    if(ok) ans=min(ans, n-(int)__builtin_popcount(i));
  }
  cout << ans << endl;
  return 0; 
}