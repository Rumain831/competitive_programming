#include<iostream>
#include<vector>
using namespace std;

//Tags: 尺取り法

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  a.push_back(-1);
  int l=0, r=-1, ans=0;
  while(l<n){
    if(r<l) r=l;
    while(r<n){
      r++;
      if(a[r-1]>a[r]) break;
    }
    ans=max(ans, r-l);
    l=r;
  }
  cout << ans << endl;
  return 0; 
}