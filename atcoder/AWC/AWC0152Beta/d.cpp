#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
using ll = long long;
ll s;

//Tags: 半分全列挙

unordered_map<ll, ll> cnt(vector<ll>& a){
  unordered_map<ll, ll> ans;
  ans[0]=1;
  int m=a.size(), mx=(1<<m);
  for(int i=1; i<mx; i++){
    ll now=0;
    bool add=true;
    for(int j=0; j<m; j++)if(i>>j&1){
      now+=a[j];
      if(now>s){
        add=false; break;
      }
    }
    if(add) ans[now]++;
  }
  return ans;
}

int main(void){
  int n; cin >> n >> s;
  vector<ll> pre, aft;
  for(int i=0; i<n; i++){
    ll x; cin >> x;
    if(i<n/2) pre.push_back(x);
    else aft.push_back(x);
  }
  auto c1=cnt(pre), c2=cnt(aft);
  ll ans=0;
  for(auto& [w, x]:c1){
    ans+=c2[s-w]*x;
  }
  if(ans==0) cout << "NO" << endl;
  else cout << (ans==1?"ALMOST":"YES") << endl;
  return 0; 
}