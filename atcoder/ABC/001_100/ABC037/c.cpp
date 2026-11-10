#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 差分更新

int main(void){
  int n, k; cin >> n >> k;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  ll now=0, ans=0;
  for(int i=0; i<k-1; i++) now+=a[i];
  for(int i=k-1; i<n; i++){
    now+=a[i];
    ans+=now;
    now-=a[i-k+1];
  }
  cout << ans << endl;
  return 0; 
}