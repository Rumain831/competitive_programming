#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main(void){
  int n, k; cin >> n >> k;
  vector<ll> a(n), b(n), dif(n);
  ll sum=0;
  for(auto&x:a) cin >> x, sum+=x;
  for(auto&x:b) cin >> x;
  for(int i=0; i<n; i++) dif[i]=b[i]-a[i];
  sort(rbegin(dif), rend(dif));
  for(int i=0; i<k; i++) sum+=dif[i];
  cout << sum << endl;
  return 0; 
}