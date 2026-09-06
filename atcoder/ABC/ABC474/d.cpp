#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using i128 = __int128_t;

//Tags: 構築

int main(void){
  int n; cin >> n;
  vector<ll> a(n), b(n), ans(n);
  __int128_t res=0;
  vector<P> c(n);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  for(int i=0; i<n; i++){
    ll d=a[i]-b[i];
    if(d>0) ans[i]=1e18;
    else ans[i]=1;
    res+=(i128)ans[i]*d;
  }
  if(res<=0) cout << "No" << endl;
  else{
    cout << "Yes" << endl;
    for(auto p:ans) cout << p << ' '; cout << endl;
  }
  return 0; 
}