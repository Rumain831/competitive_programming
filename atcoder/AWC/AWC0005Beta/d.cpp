#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main(void){
  int n, k; cin >> n >> k;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  ll left=0, right=1e18;
  while(right-left>1){
    ll mid=(left+right)/2;
    int cnt=0;
    ll now=0;
    for(int i=0; i<n; i++){
      if(now+a[i]<mid) now+=a[i];
      else cnt++, now=0;
    }
    if(cnt>=k) left=mid;
    else right=mid;
  }
  cout << left << endl;
  return 0;
}