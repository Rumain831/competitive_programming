#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 差分更新

int main(void){
  int n, k; cin >> n >> k;
  vector<ll> a(n);
  ll sum=0, now=0, mx=-1e18;
  for(auto&x:a) cin >> x, sum+=x;
  for(int i=0; i<k-1; i++) now+=a[i];
  for(int i=k-1; i<n; i++){
    now+=a[i];
    mx=max(mx, now);
    now-=a[i-k+1];
  }
  cout << sum+mx << endl;
  return 0; 
}