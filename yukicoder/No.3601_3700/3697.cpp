#include<iostream>
#include<vector>
#include<set>
using namespace std;
using ll = long long;

//Tags: 半分全列挙
//Level: 3

vector<set<ll>> all(vector<ll>& a){
  int n=a.size();
  vector<set<ll>> ans(n+1);
  int mx=(1<<n);
  for(int i=0; i<mx; i++){
    ll now=0, c=0;
    for(int j=0; j<n; j++)if(i>>j&1) c++, now+=a[j];
    ans[c].insert(now);
  }
  return ans;
}

int main(void){
  int n; cin >> n;
  vector<ll> pre, aft;
  ll sum=0;
  for(int i=0; i<n; i++){
    ll x; cin >> x; sum+=x;
    if(i<n/2) pre.push_back(x);
    else aft.push_back(x);
  }
  auto s1=all(pre);
  auto s2=all(aft);
  ll ans=1e18;
  for(int i=0; i<=n/2; i++){
    for(auto p:s1[i]){
      ll x=sum-p*2, opp=n/2-i;
      auto it=s2[opp].upper_bound(x/2);
      if(it!=end(s2[opp])) ans=min(ans, abs(x-2**(it)));
      if(it!=begin(s2[opp])) it--;
      if(it!=end(s2[opp])) ans=min(ans, abs(x-2**(it)));
    }
  }
  cout << ans << endl;
  return 0; 
}