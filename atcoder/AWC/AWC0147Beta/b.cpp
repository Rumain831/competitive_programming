#include<iostream>
#include<vector>
using namespace std;

//Tags: 尺取り法

int main(void){
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  int l=0, r=-1, ans=0;
  while(l<n){
    if(l>r) r=l;
    int pre=a[l];
    while(r<n&&abs(pre-a[r])<=k){
      pre=a[r], r++;
    }
    ans=max(ans, r-l);
    l=r;
  }
  cout << ans << endl;
  return 0; 
}