#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 貪欲法
//aを添字 [1, b_1], [b_1+1, b_2], ..., [b_(m-1)+1, b_m], [b_m+1, n] で分割する
//[b_m+1, n]は値を変えようがないのでそのまま
//その他の部分は abs(総和) を足せる
void solve(){
  int n, m; cin >> n >> m;
  vector<ll> a(n), b(m);
  for(auto&x:a) cin >> x; 
  for(auto&x:b) cin >> x, x--; 
  sort(begin(b), end(b));
  ll ans=0, l=0;
  for(int i=0; i<m; i++){
    ll now=0;
    for(int j=l; j<=b[i]; j++) now+=a[j];
    ans+=abs(now);
    l=b[i]+1;
  }
  for(int i=l; i<n; i++) ans+=a[i];
  cout << ans << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}