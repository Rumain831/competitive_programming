#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 条件分岐

int main(void){
  int n, k; cin >> n >> k;
  vector<pair<int, int>> po(n);
  for(int i=0; i<n; i++){
    for(int j=0; j<3; j++){
      int p; cin >> p; 
      po[i].first+=p;
    }
    po[i].second=i;
  }
  sort(po.rbegin(), po.rend());
  int lim=po[k-1].first-300;
  vector<int> ans(n);
  for(int i=0; i<n; i++){
    auto [score, idx]=po[i];
    if(score>=lim) ans[idx]=1;
  }
  for(int i=0; i<n; i++) cout << (ans[i]?"Yes":"No") << endl;
  return 0;
}