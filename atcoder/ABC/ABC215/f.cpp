#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  int n; cin >> n;
  vector<P> p;
  for(int i=0; i<n; i++){
    int x, y; cin >> x >> y;
    p.emplace_back(x, y);
  }
  sort(p.begin(), p.end());
  vector<int> mini(n), maxi(n), x(n), y(n);
  for(int i=0; i<n; i++) x[i]=p[i].first, y[i]=p[i].second;
  auto [a, b]=p.back();
  mini[n-1]=maxi[n-1]=b;
  for(int i=n-2; i>=0; i--){
    mini[i]=min(mini[i+1], y[i]);
    maxi[i]=max(maxi[i+1], y[i]);
  }
  ll left=0, right=2e9;
  while(right-left>1){
    ll mid=(left+right)/2;
    bool fa=true;
    for(int i=0; i<n; i++){
      int q=lower_bound(x.begin(), x.end(), x[i]+mid)-x.begin();
      q=max(q, i);
      if(q==n) break;
      int mi=mini[q], ma=maxi[q];
      if(abs(mi-y[i])>=mid||abs(ma-y[i])>=mid){
        fa=false; break;
      }
    }
    if(fa) right=mid;
    else left=mid;
  }
  cout << left << endl;
  return 0;
}