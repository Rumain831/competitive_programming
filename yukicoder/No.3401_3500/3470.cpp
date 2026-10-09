#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 主客転倒
//Level: 2.5

int main(void){
  int n; cin >> n;
  vector<ll> t(n);
  for(auto&x:t) cin >> x;
  sort(begin(t), end(t));
  ll ans=0, sum=0;
  for(int i=0; i<n; i++){
    ans+=t[i]*i-sum;
    sum+=t[i];
  }
  cout << ans << endl;
  return 0; 
}