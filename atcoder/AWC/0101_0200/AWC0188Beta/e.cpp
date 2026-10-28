#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 最適化

int main(void){
  int n; cin >> n;
  vector<ll> c(n);
  for(auto&x:c) cin >> x;
  sort(begin(c), end(c));
  if(n<=2){
    cout << c[n-1]-c[0] << endl; return 0;
  }
  ll ans=0;
  for(int t=0; t<2; t++){
    int edge[2]={n-1, n-1};
    int x=0, l=0, r=n-2;
    ll now=0;
    while(l<=r){
      if(x&1){
        for(int y=0; y<2; y++){
          if(l>r) break;
          now+=abs(c[edge[y]]-c[r]);
          edge[y]=r--;
        }
      }
      else{
        for(int y=0; y<2; y++){
          if(l>r) break;
          now+=abs(c[edge[y]]-c[l]);
          edge[y]=l++;
        }
      }
      x++;
    }
    ans=max(ans, now);
    reverse(begin(c), end(c));
  }
  cout << ans << endl;
  return 0; 
}