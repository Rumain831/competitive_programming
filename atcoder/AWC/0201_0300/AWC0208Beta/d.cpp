#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 貪欲法

int main(void){
  int n; cin >> n;
  vector<P> vec;
  for(int i=0; i<n; i++){
    ll t, p; cin >> t >> p;
    vec.emplace_back(t, p);
  }
  sort(begin(vec), end(vec), [](const P& a, const P& b){
    auto [t1, p1]=a;
    auto [t2, p2]=b;
    return t1*p2<t2*p1;
  });
  ll sum=0, ans=0;
  for(auto [t, p]:vec){
    sum+=t;
    ans+=sum*p;
  }
  cout << ans << endl;
  return 0; 
}