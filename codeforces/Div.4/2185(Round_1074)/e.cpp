#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
using ll = long long;

//Tags: Simulation
//https://codeforces.com/contest/2185/problem/E
//各ロボットの左右にある針に当たる時刻が分かれば良い

void solve(){
  int n, m, k; cin >> n >> m >> k;
  vector<ll> a(n), imos(k+1);
  set<ll> spike;
  for(auto&x:a) cin >> x;
  while(m--){
    int b; cin >> b;
    spike.insert(b);
  }
  spike.insert(-1e18);
  spike.insert(1e18);
  ll now=0;
  map<ll, int> op;
  string s; cin >> s;
  for(int i=0; i<k; i++){
    now+=(s[i]=='L'?-1:1);
    if(op.count(now)==0) op[now]=i;
  }
  for(int i=0; i<n; i++){
    int mi=1e9;
    auto it=spike.lower_bound(a[i]);
    ll d=(*it)-a[i];
    if(op.count(d)) mi=min(mi, op[d]);
    it--;
    d=(*it)-a[i];
    if(op.count(d)) mi=min(mi, op[d]);
    if(mi!=1e9) imos[mi]++;
  }
  for(int i=0; i<k; i++) imos[i+1]+=imos[i];
  for(int i=0; i<k; i++) cout << n-imos[i] << (i==k-1?'\n':' ');
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}