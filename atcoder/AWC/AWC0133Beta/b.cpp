#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 貪欲法

int main(void){
  int n, k, t; cin >> n >> k >> t; t--;
  vector<ll> a(n);
  ll ans=0;
  for(int i=0; i<n; i++){
    cin >> a[i];
    if(i==t){
      ans+=a[i];
      a[i]=-1e18;
    }
  }
  sort(rbegin(a), rend(a));
  for(int i=0; i<k-1; i++) ans+=a[i];
  cout << ans << endl;
  return 0; 
}