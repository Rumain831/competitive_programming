#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: 実装

int main(void){
  int n, k, m; cin >> n >> k >> m;
  vector<P> po;
  for(int i=0; i<n; i++){
    int s; cin >> s;
    po.emplace_back(s, -i);
  }
  for(int i=0; i<m; i++){
    int d; cin >> d; d--;
    po[d].first=-1e9;
  }
  sort(rbegin(po), rend(po));
  for(int i=0; i<k; i++)if(po[i].second==0){
    cout << "Yes" << endl; return 0;
  }
  cout << "No" << endl;
  return 0; 
}