#include<iostream>
#include<vector>
using namespace std;

//Tags: 二分探索, 貪欲法
//解説URL: https://twitter.com/e869120/status/1377027868518064129

int main(void){
  int n, l, k;
  cin >> n >> l >> k; 
  vector<int> a(n+2), cut(n+1);
  for(int i=0; i<n; i++) cin >> a[i+1];
  a.back()=l;
  for(int i=0; i<n+1; i++) cut[i]=a[i+1]-a[i];
  auto judge=[&](int x){
    int cnt=0, l=0;
    while(l<=n){
      int r=l, now=0;
      while(r<=n){
        now+=cut[r++];
        if(now>=x) break;
      }
      if(now>=x) cnt++;
      l=r;
    }
    return cnt>=(k+1);
  };
  int left=0, right=l+10;
  while(right-left>1){
    int mid=(left+right)/2;
    if(judge(mid)) left=mid;
    else right=mid;
  }
  cout << left << endl;
  return 0;
}