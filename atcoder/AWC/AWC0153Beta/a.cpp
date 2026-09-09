#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 配列

int main(void){
  int n, k; cin >> n >> k;
  vector<ll> a(n), b(k);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x, x--;
  for(int i=0; i<k; i++){
    ll c; cin >> c;
    a[b[i]]=c;
  }
  ll ans=0;
  for(int i=0; i<n-1; i++) ans+=abs(a[i]-a[i+1]);  
  cout << ans << endl;
  return 0; 
}