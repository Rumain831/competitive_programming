#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 期待値
//Level: 2.5

int main(void){
  int n, k; cin >> n >> k;
  vector<ll> p(n);
  for(int i=0; i<k; i++){
    int l, s; cin >> l >> s;
    while(l--){
      int b; cin >> b; b--;
      p[b]|=s;
    }
  }
  ll mod=998244353, ans=0, inv2=499122177;
  for(int i=0; i<n; i++) ans+=p[i]%mod*inv2%mod, ans%=mod;
  cout << ans << endl;
  return 0; 
}