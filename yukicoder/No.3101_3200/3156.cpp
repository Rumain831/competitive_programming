#include<iostream>
#include<set>
using namespace std;
using ll = long long;

//Tags: 全探索
//Level: 1.5

int main(void){
  ll k, n; cin >> k >> n;
  set<ll> ans;
  for(ll i=1; i*i*i*i*i*i<=n; i++){
    ll six=i*i*i*i*i*i;
    for(ll j=1; six+j*j*j*j<=n; j++){
      ll tar=six+j*j*j*j;
      if(tar%k) continue;
      ll left=1, right=1e9;
      while(right-left>1){
        ll mid=(left+right)/2;
        if(mid*mid<=tar/k) left=mid;
        else right=mid;
      }
      if(k*left*left==tar){
        ans.insert(tar);
      }
    }
  }
  cout << ans.size() << endl;
  return 0;
}