#include<iostream>
#include<vector>
using namespace std;

//Tags: 累積和

int main(void){
  int n, l, r; cin >> n >> l >> r;
  vector<int> t(n), sum(n+1);
  for(auto&x:t){
    cin >> x;
    x=(l<=x&&x<=r?1:-1);
  }
  for(int i=0; i<n; i++) sum[i+1]=sum[i]+t[i];
  int ans=-1e9, mi=0;
  for(int i=0; i<n; i++){
    ans=min(ans, sum[i+1]-mi);
    mi=min(mi, sum[i+1]);
  }
  cout << ans << endl;
  return 0; 
}