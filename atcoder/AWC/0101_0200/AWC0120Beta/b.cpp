#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 全探索, 区間

int main(void){
  int n, k, d; cin >> n >> k >> d; d--;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  ll ans=-1e18, now=0;
  for(int i=0; i<k-1; i++) now+=a[i];
  for(int i=k-1; i<n; i++){
    now+=a[i];
    if(i-k+1<=d&&d<=i) ans=max(ans, now);
    now-=a[i-k+1];
  }
  cout << ans << endl;
  return 0; 
}