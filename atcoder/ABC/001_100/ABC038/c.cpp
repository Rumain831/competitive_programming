#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 尺取り法

int main(void){
  int n; cin >> n;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  ll ans=0, l=0, r=-1;
  while(l<n){
    if(r<=l) r=l+1;
    while(r<n&&a[r-1]<a[r]) r++;
    ll len=r-l;
    ans+=len*(len+1)/2;
    l=r;
  }
  cout << ans << endl;
  return 0; 
}