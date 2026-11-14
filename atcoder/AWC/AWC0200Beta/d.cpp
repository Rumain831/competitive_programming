#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 条件を満たすものの個数

int main(void){
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  ll sum=0, ans=0;
  for(auto&x:a) cin >> x, sum+=x;
  for(int i=0; i<n; i++){
    ans+=(a[i]*(n-1)>=k*(sum-a[i]));
  }
  cout << ans << endl;
  return 0; 
}