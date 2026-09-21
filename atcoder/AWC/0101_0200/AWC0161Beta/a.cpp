#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 順列全探索

int main(void){
  int n; cin >> n;
  vector<ll> a(n), p(n);
  for(int i=0; i<n; i++) cin >> a[i], p[i]=i;
  ll ans=-1;
  do{
    ll now=0;
    for(int i=0; i<n-1; i++) now+=abs(a[p[i]]-a[p[i+1]]);
    ans=max(ans, now);
  }while(next_permutation(begin(p), end(p)));
  cout << ans << endl;
  return 0; 
}