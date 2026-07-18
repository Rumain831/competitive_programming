#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main(void){
  int n; cin >> n;
  vector<ll> h(n);
  for(auto&x:h) cin >> x;
  h.push_back(0);
  sort(h.begin(), h.end());
  ll d=h.back()-h[0];
  cout << 2ll*d << endl;
  return 0;
}