#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  int n, m; cin >> n >> m;
  vector<vector<P>> event(m);
  vector<int> cnt(n+1);
  vector<int> col(n);
  for(int i=0; i<n; i++){
    int a, d, b; cin >> a >> d >> b; d--;
    event[0].emplace_back(i, a);
    event[d].emplace_back(i, b);
  }
  int ans=1;
  cnt[0]=n;
  for(int i=0; i<m; i++){
    for(auto [id, co]:event[i]){  
      if(--cnt[col[id]]==0) ans--;
      col[id]=co;
      if(++cnt[col[id]]==1) ans++;
    }
    cout << ans << '\n';
  }
  return 0; 
}