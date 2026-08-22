#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<int, int>;

//Tags: 全探索, 実装

int main(void){
  int n, m; cin >> n >> m;
  vector<int> pl(n), cnt(m+1); 
  vector<P> tour;
  vector<vector<int>> appear(n);
  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b; a--, b--;
    tour.emplace_back(a, b);
    pl[a]++, pl[b]++;
    appear[a].push_back(i);
    appear[b].push_back(i);
  }
  for(int i=0; i<n; i++) cnt[pl[i]]++;
  ll ans=0;
  for(int i=0; i<n; i++){
    int x=pl[i];
    if(x==0){
      ans+=cnt[m];
      continue;
    }
    if(x==m){
      ans+=n-1; continue;
    }
    for(auto j:appear[i]){
      auto [a, b]=tour[j];
      cnt[pl[a]--]--, cnt[pl[b]--]--;
      cnt[pl[a]]++, cnt[pl[b]]++;
    }
    int rem=m-x;
    ll add=cnt[rem];
    ans+=add;
    for(auto j:appear[i]){
      auto [a, b]=tour[j];
      cnt[pl[a]++]--, cnt[pl[b]++]--;
      cnt[pl[a]]++, cnt[pl[b]]++;
    }
  }
  cout << ans/2 << endl;
  return 0; 
}