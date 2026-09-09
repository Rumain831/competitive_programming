#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;

//Tags: 最適化, 余り
//Level: 2.5

int main(void){
  ll n, m; cin >> n >> m;
  map<ll, int> cnt;
  for(int i=0; i<n; i++){
    ll x; cin >> x; x%=m;
    cnt[x]++;
    cnt[(m-x)%m]+=0;
  } 
  int ans=0;
  for(auto&[x, c]:cnt){
    ll opp=m-x;
    if(x>opp) break;
    opp%=m;
    if(x==opp) ans++;
    else ans+=max(cnt[x], cnt[opp]);  
  }
  cout << ans << endl;
  return 0; 
}