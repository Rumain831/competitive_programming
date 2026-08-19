#include<iostream>
#include<queue>
using namespace std;
using P = pair<int, int>;

//Tags: 貪欲法, 区間

int main(void){
  int n, d; cin >> n >> d;
  priority_queue<P, vector<P>, greater<P>> pri;
  for(int i=0; i<n; i++){
    int l, r; cin >> l >> r;
    pri.emplace(r, l);
  }
  int ans=0;
  int lim=-d;
  while(pri.size()){
    while(pri.size()){
      auto [r, l]=pri.top(); pri.pop();
      if(lim<l){
        ans++;
        lim=r+d-1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}