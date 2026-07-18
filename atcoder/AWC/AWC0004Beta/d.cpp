#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

int main(void){
  int n, m; cin >> n >> m;
  vector<P> seg;
  for(int i=0; i<m; i++){
    int l, r; cin >> l >> r;
    seg.emplace_back(l, r);
  }
  sort(seg.begin(), seg.end());
  priority_queue<int, vector<int>, greater<int>> pri;
  int idx=0, ok=1;
  for(int ok=1; ok<=n; ok++){
    while(idx<m&&seg[idx].first==ok){
      pri.push(seg[idx].second);
      idx++;
    }
    if(pri.size()){
      int r=pri.top();
      if(r<ok){
        cout << "No" << endl; return 0;
      }
      pri.pop();
    }
  }
  cout << (pri.size()?"No":"Yes") << endl;
  return 0;
}