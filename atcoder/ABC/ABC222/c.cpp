#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: Simulation

int main(void){
  int n, m; cin >> n >> m;
  vector<string> hand(2*n);
  for(auto&x:hand) cin >> x;
  vector<pair<int, int>> order;
  for(int i=0; i<2*n; i++) order.emplace_back(0, i);
  for(int i=0; i<m; i++){
    for(int j=0; j<2*n; j+=2){
      auto& [cnt1, id1]=order[j];
      auto& [cnt2, id2]=order[j+1];
      char p=hand[id1][i], q=hand[id2][i];
      if(p=='G'){
        if(q=='P') cnt2--;
        else if(q=='C') cnt1--;
      }
      else if(p=='C'){
        if(q=='G') cnt2--;
        else if(q=='P') cnt1--;
      }
      else{
        if(q=='C') cnt2--;
        else if(q=='G') cnt1--;
      }
    }
    sort(order.begin(), order.end());
  }
  vector<int> ans(2*n);
  for(int i=0; i<2*n; i++){
    ans[i]=order[i].second+1;
  }
  for(auto p:ans) cout << p << endl;
  return 0;
}
