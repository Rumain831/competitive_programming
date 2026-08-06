#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: Simulation
//https://codeforces.com/contest/2185/problem/D
//変更した箇所だけ覚えておけば、元に戻す作業も単純。
//変更を受けるのは高々m箇所なので十分高速。

void solve(){
  ll n, m, h; cin >> n >> m >> h;
  vector<ll> a(n), add(n);
  for(auto&x:a) cin >> x;
  vector<int> pos;
  while(m--){
    int b; ll c; cin >> b >> c; b--;
    add[b]+=c;
    pos.push_back(b);
    if(a[b]+add[b]>h){
      while(pos.size()){
        add[pos.back()]=0;
        pos.pop_back();
      }
    }
  }
  for(int i=0; i<n; i++) cout << a[i]+add[i] << (i==n-1?'\n':' ');
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}