#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: 区間

int main(void){
  int n, m; cin >> n >> m;
  vector<P> L, R;
  vector<int> mxl(m+2), mxr(m+2);
  for(int i=0; i<n; i++){
    int l, r, s; cin >> l >> r >> s; l--, r--;
    L.emplace_back(r, s);
    R.emplace_back(l, s);
  }
  sort(begin(L), end(L));
  sort(rbegin(R), rend(R));
  int id=0, now=0;
  for(int i=0; i<m; i++){
    while(id<n){
      auto [r, s]=L[id];
      if(i<r) break;
      else now+=s, id++;
    }
    mxl[i+1]=now;
  }
  id=0, now=0;
  for(int i=m-1; i>=0; i--){
     while(id<n){
      auto [l, s]=R[id];
      if(i>l) break;
      else now+=s, id++;
    }
    mxr[i+1]=now;
  }
  int ans=0;
  for(int i=1; i<=m; i++) ans=max(ans, mxl[i-1]+mxr[i+1]);
  cout << ans << endl;
  return 0; 
}