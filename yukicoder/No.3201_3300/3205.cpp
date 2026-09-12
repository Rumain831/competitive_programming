#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: XOR
//Level: 2.5

int main(void){
  int n, q; cin >> n >> q;
  vector<ll> a(n);
  vector cnt(26, vector<ll>(n+1));
  for(int i=0; i<n; i++){
    cin >> a[i];
    for(int j=0; j<26; j++){
      cnt[j][i+1]=cnt[j][i]+(a[i]>>j&1);
    }
  }
  while(q--){
    int l, r; cin >> l >> r; l--;
    ll len=r-l, ans=0;
    for(int i=0; i<26; i++){
      ll one=cnt[i][r]-cnt[i][l], two=len-one;
      ans+=one*two*(1ll<<i);
    }
    cout << ans << '\n';
  }
  return 0; 
}