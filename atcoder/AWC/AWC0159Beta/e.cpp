#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 半分全列挙

vector<vector<ll>> all(vector<ll>& a){
  int m=a.size(), mx=(1<<m);
  vector<vector<ll>> ans(m+1);
  for(int i=0; i<mx; i++){
    ll now=0, c=0;
    for(int j=0; j<m; j++)if(i>>j&1) now+=a[j], c++;
    ans[c].push_back(now);
  }
  for(int i=0; i<=m; i++) sort(begin(ans[i]), end(ans[i]));
  return ans;
}

int main(void){
  ll n, k, x; cin >> n >> k >> x;
  vector<ll> pre, aft;
  for(int i=0; i<n; i++){
    ll a; cin >> a;
    if(i<n/2) pre.push_back(a);
    else aft.push_back(a);
  }
  auto all1=all(pre);
  auto all2=all(aft);
  int c1=pre.size(), c2=aft.size();
  ll ans=0;
  for(int i=0; i<=c1; i++){
    int oc=k-i;
    if(oc<0||oc>c2) continue;
    for(auto p:all1[i]){
      ll add=end(all2[oc])-lower_bound(begin(all2[oc]), end(all2[oc]), x-p);
      ans+=add;
    }
  }
  cout << ans << endl;
  return 0; 
}