#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 二分探索

int main(void){
  int n; cin >> n;
  vector<ll> h(n), s(n);
  for(int i=0; i<n; i++) cin >> h[i] >> s[i];
  ll left=0, right=1e18; 
  auto judge=[&](ll x){
    vector<ll> rem;
    for(int i=0; i<n; i++){
      if(x<h[i]) return false;
      ll sec=(x-h[i])/s[i];
      rem.push_back(sec);
    }
    sort(begin(rem), end(rem));
    for(int i=0; i<n; i++){
      if(rem[i]<i) return false;
    }
    return true;
  };
  while(right-left>1){
    ll mid=(left+right)/2;
    if(judge(mid)) right=mid;
    else left=mid;
  }
  cout << right << endl;
  return 0; 
}