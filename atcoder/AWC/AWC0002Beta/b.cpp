#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<ll> a(n), b(m);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x, x--;
  ll cnt=0, sum=0;
  for(int i=0; i<m; i++){
    if(a[b[i]]<k) cnt++, sum+=a[b[i]];
  }
  cout << cnt << ' ' << sum << endl;
  return 0;
}