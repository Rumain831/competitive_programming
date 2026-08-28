#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 累積和
//Level: 1.5

int main(void){
  int n, q; cin >> n >> q;
  vector<ll> s(n), sum(n+1);
  for(int i=0; i<n; i++) cin >> s[i], sum[i+1]=sum[i]+s[i];
  while(q--){
    int l, r, k; cin >> l >> r >> k;
    cout << sum[r]-sum[l-1] << '\n';
  }
  return 0; 
}