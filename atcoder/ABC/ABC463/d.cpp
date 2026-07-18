#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(void){
  int n, k; cin >> n >> k;
  vector<P> cloth;
  for(int i=0; i<n; i++){
    ll l, r; cin >> l >> r;
    cloth.emplace_back(r, l);
  }
  sort(cloth.begin(), cloth.end());
  ll left=1, right=1e18;
  auto judge=[&](ll tar){
    int id=0;
    ll last=-2e18, cnt=0;
    while(id<n){
      auto [r, l]=cloth[id];
      if(last+tar>l){
        id++; continue;
      }
      else{
        last=r, cnt++; id++;
      }
    }
    if(cnt>=k) return true;
    else return false;
  };
  if(!judge(1)){
    cout << -1 << endl; return 0;
  }
  while(right-left>1){
    ll mid=(left+right)/2;
    if(judge(mid)) left=mid;
    else right=mid;
  }
  cout << left << endl;
  return 0; 
}