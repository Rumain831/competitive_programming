#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<int, int>;

//Tags: 最適化, 貪欲法
//Level: 1.5

int main(void){
  int n; cin >> n;
  vector<P> a(2*n);
  for(int i=0; i<2*n; i++){
    cin >> a[i].first;
    a[i].second=i+1;
  }
  sort(begin(a), end(a));
  vector<P> ans;
  ll val=0;
  for(int i=0; i<n; i++){
    auto [a1, i1]=a[i];
    auto [a2, i2]=a[2*n-1-i];
    ans.emplace_back(i1, i2);
    val+=abs(a1-a2);
  }
  cout << val << endl;
  for(auto [p, q]:ans) cout << p << ' ' << q << endl;
  return 0; 
}