#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
using ll = long long;

//この実装だとn=1のときにpreではなくaftに要素が入ることに注意
int main(void){
  ll n, s; cin >> n >> s;
  vector<ll> pre, aft;
  for(int i=0; i<n; i++){
    ll a; cin >> a;
    if(i<n/2) pre.push_back(a);
    else aft.push_back(a);
  }
  auto all=[&](vector<ll>& p, unordered_map<ll, ll>& ans){
    int m=p.size();
    if(m==0){
      ans[0]++;
      return;
    }
    for(int i=0; i<(1<<m); i++){
      ll now=0;
      for(int j=0; j<m; j++)if(i>>j&1){
        now+=p[j];
      }
      ans[now]++;
    }
  };
  unordered_map<ll, ll> cntp, cnta;
  all(pre, cntp);
  all(aft, cnta);
  ll ans=0;
  for(auto&[yen, c]:cntp){
    if(cnta.count(s-yen)) ans+=c*cnta[s-yen];
  }
  cout << ans << endl;
  return 0;
}