#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main(void){
  int n, d; cin >> n >> d;
  vector<ll> a(n);
  ll ans=0;
  for(auto&x:a) cin >> x;
  sort(begin(a), end(a));
  for(int j=1; j<n; j++){
    if(abs(a[j-1]-a[j])>d) ans+=abs(a[j-1]-a[j]);
  }
  cout << ans << endl;
  return 0; 
}