#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;

int main(void){
  int n, q; cin >> n >> q;
  deque<int> sum;
  vector<int> cnt(n);
  int zero=0, c=0;
  for(int i=0; i<3e5+1; i++) sum.push_back(n);
  while(q--){
    int t; cin >> t;
    if(t==1){
      int x; cin >> x; x--;
      int p=cnt[x]-zero;
      sum[p]--;
      cnt[x]++;
      if(sum[0]==0){
        sum.pop_front();
        sum.push_back(n);
        zero++;
      }
    }
    else{
      int y; cin >> y; 
      cout << n-sum[y-1] << '\n';
    }
  }
  return 0; 
}