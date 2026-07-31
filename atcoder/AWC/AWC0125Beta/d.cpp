#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 尺取り法

int main(void){
  int n, d; cin >> n >> d;
  vector<P> fruit;
  ll ans=-1e18;
  for(int i=0; i<n; i++){
    ll c, p; cin >> c >> p;
    if(p-c>0) fruit.emplace_back(p, p-c); 
    ans=max(ans, p-c);
  }
  sort(begin(fruit), end(fruit));
  n=fruit.size();
  int l=0, r=-1;
  ll now=0;
  while(l<n){
    if(r<l) r=l;
    ll mi=fruit[l].first; 
    while(r<n){
      auto [p, get]=fruit[r];
      if(p>mi+d) break;
      now+=get;
      r++;
    }
    ans=max(ans, now);
    now-=fruit[l].second;
    l++;
  }
  cout << ans << endl;
  return 0; 
}