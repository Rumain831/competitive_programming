#include<iostream>
#include<vector>
using namespace std;

//Tags: 累積和

int main(void){
  int n, m; cin >> n >> m;
  vector<int> sum(n+2), cnt(n+2);
  vector<int> L(m), R(m);
  for(int i=0; i<m; i++){
    int l, r; cin >> l >> r; 
    sum[l]++, sum[r+1]--;
    L[i]=l, R[i]=r;
  }
  int base=0;
  for(int i=0; i<=n; i++){
    sum[i+1]+=sum[i];
    base+=(sum[i+1]>0);
    cnt[i+1]=cnt[i]+(sum[i+1]==1);
  }
  int ans=0;
  for(int i=0; i<m; i++){
    int c=cnt[R[i]]-cnt[L[i]-1];
    ans=max(ans, base-c);
  }
  cout << ans << endl;
  return 0; 
}