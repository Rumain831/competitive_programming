#include<iostream>
#include<queue>
using namespace std;
using ll = long long;

//Tags: 二分探索, 貪欲法
//Level: 2.5

int main(void){
  int n; cin >> n;
  priority_queue<ll> pri;
  for(int i=0; i<n; i++){
    ll h; cin >> h;
    pri.push(h);
  }
  auto judge=[&](ll x){
    priority_queue<ll> now=pri;
    while(x--&&now.size()){
      ll p=min<ll>(x, 60), minus=(1ll<<p);
      ll d=now.top(); now.pop();
      d-=minus;
      if(d<=0) continue;
      now.push(d);
    }
    return now.empty();
  };
  ll left=0, right=n+61;
  while(right-left>1){
    ll mid=(left+right)/2;
    if(judge(mid)) right=mid;
    else left=mid;
  }
  cout << right << endl;
  return 0; 
}