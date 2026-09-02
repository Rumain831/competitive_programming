#include<iostream>
#include<vector>
using namespace std;

//Tags: 条件を満たすもの

int main(void){
  int n, d, k; cin >> n >> d >> k;
  vector<int> cnt(n+1);
  for(int i=0; i<d; i++){
    int m; cin >> m;
    while(m--){
      int s; cin >> s;
      cnt[s]++;
    }
  }
  vector<int> ans;
  for(int i=0; i<=n; i++)if(cnt[i]>=k) ans.push_back(i);
  if(ans.empty()) cout << -1 << endl;
  else{
    for(auto p:ans) cout << p << ' '; cout << endl; 
  }
  return 0; 
}