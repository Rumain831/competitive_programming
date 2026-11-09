#include<iostream>
#include<vector>
using namespace std;

//Tags: 累積和

int main(void){
  int n, q; cin >> n >> q;
  vector<int> h(n), sum(n+1);
  for(auto&x:h) cin >> x;
  for(int i=1; i<n-1; i++){
    sum[i+1]=(h[i-1]>h[i]&&h[i]<h[i+1]);
  }
  for(int i=0; i<n; i++) sum[i+1]+=sum[i];
  while(q--){
    int l, r; cin >> l >> r;
    cout << sum[r-1]-sum[l] << endl;
  }
  return 0; 
}