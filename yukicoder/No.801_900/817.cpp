#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: イベントソート, 区間

int main(void){
  ll n, k; cin >> n >> k;
  vector<P> event;
  for(int i=0; i<n; i++){
    int a, b; cin >> a >> b;
    event.emplace_back(a, 1);
    event.emplace_back(b+1, -1);
  }
  int m=event.size();
  sort(begin(event), end(event));
  int id=0, c=0;
  while(k){
    ll pos=event[id].first, r;
    while(id<m){
      auto [npos, t]=event[id];
      r=npos;
      if(pos!=npos) break;
      c+=t, id++;
    }
    ll len=r-pos;
    if(len*c<k) k-=len*c;
    else{
      k--;
      ll ad=k/c;
      cout << pos+ad << endl; return 0;
    }
  }
  return 0; 
}