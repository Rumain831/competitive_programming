#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 貪欲法

int main(void){
  int n, w; cin >> n >> w;
  vector<pair<ll, ll>> cheese;
  for(int i=0; i<n; i++){
    ll a, b; cin >> a >> b;
    cheese.emplace_back(a, b);
  }
  sort(cheese.rbegin(), cheese.rend());
  ll ans=0, sumw=0;
  for(int i=0; i<n; i++){
    auto [a, b]=cheese[i];
    if(sumw+b<w){
      sumw+=b;
      ans+=a*b;
    }
    else{
      ans+=a*(w-sumw);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}