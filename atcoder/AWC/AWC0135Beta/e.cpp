#include<iostream>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
using namespace std;
using ll = long long;
using tu = tuple<ll, int, int>;

//Tags: 桁dp

ll k;

ll f(ll x){
  if(x==0) return 0ll;
  string s=to_string(x);
  int d=s.size();
  map<tu, ll> dp;
  dp[{0, 0, 0}]=1;
  for(int i=0; i<d; i++){
    map<tu, ll> old;
    swap(old, dp);
    int now=s[i]-'0';
    for(auto& [p, c]:old){
      auto& [x, ika, st]=p;
      int r=(ika?9:now);
      for(int p=0; p<=r; p++){
        int nika=(ika||p<now);
        int nst=(st||p);
        ll nx=x*p;
        if(x==0&&st==0) nx=p;
        dp[{nx, nika, nst}]+=c;
      }
    }
  }
  ll ans=dp[{k, 0, 1}];
  ans+=dp[{k, 1, 1}];
  return ans;
}

int main(void){
  ll l, r; cin >> l >> r >> k;
  cout << f(r)-f(l-1) << endl;
  return 0; 
}