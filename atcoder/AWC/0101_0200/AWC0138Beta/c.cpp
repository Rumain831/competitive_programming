#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 尺取り法

int main(void){
  ll n, k; cin >> n >> k;
  vector<ll> a(n), b(n);
  for(int i=0; i<n; i++) cin >> a[i] >> b[i];
  ll ans=0, suma=0, sumb=0;
  int l=0, r=-1;
  while(l<n){
    if(r<l) r=l, suma=0, sumb=0;
    while(r<n){
      if(sumb+b[r]<=k) suma+=a[r], sumb+=b[r++];
      else break;
    }
    ans=max(ans, suma);
    if(l<r) suma-=a[l], sumb-=b[l];
    l++;
  }
  cout << ans << endl;
  return 0; 
}