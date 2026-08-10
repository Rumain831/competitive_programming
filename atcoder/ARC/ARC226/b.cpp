#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 二分探索, 貪欲法

void solve(){
  int n, m; cin >> n >> m;
  vector<ll> a(m);
  for(auto&x:a) cin >> x;
  ll left=-1, right=2e18;
  auto judge=[&](ll x){
    priority_queue<P> pri;
    pri.emplace(x, n);
    for(int i=m-1; i>=0; i--){
      ll rem=a[i], per=(1ll<<i);
      while(rem){
        if(pri.empty()) return false;
        auto [w, c]=pri.top(); pri.pop();
        if(w<per) return false;
        ll in=w/per;
        if(in<=rem/c){
          rem-=in*c, w-=per*in;
          if(w) pri.emplace(w, c);
        }
        else{
          ll full=rem/in, r=rem%in;
          {//in個入れる
            ll nw=w-per*in;
            if(nw&&full) pri.emplace(nw, full);
          }
          if(r){
            ll nw=w-per*r;
            if(nw) pri.emplace(nw, 1);
          }
          {
            c-=full+(r>0);
            if(c) pri.emplace(w, c);
          }
          rem=0;
        }
      }
    }
    return true;
  };
  while(right-left>1){
    ll mid=(left+right)/2;
    if(judge(mid)) right=mid;
    else left=mid;
  }
  cout << right << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}