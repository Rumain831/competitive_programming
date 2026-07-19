#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using ll = long long;

int main(void){
  int n, m; cin >> n >> m;
  int nn=1e5+1;
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
  vector<int> a(n), cnt(m+1);
  for(auto&p:a) cin >> p;
  set<int> ng;
  for(int i=0; i<n; i++){
    int copy=a[i];
    while(copy>1){
      ng.insert(yakusu[copy]);
      copy/=yakusu[copy];
    }
  }
  for(auto p:ng){
    int copy=p;
    while(copy<=m){
      cnt[copy]++;
      copy+=p;
    }
  }
  vector<int> ans;
  for(int i=1; i<=m; i++) if(cnt[i]==0) ans.push_back(i);
  cout << ans.size() << endl;
  for(auto p:ans) cout << p << endl;
  return 0; 
}