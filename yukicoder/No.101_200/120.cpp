#include<iostream>
#include<map>
using namespace std;

//Tags: Hall条件
//Level: 2

void solve(){
  int n; cin >> n;
  map<int, int> cnt;
  for(int i=0; i<n; i++){
    int l; cin >> l;
    cnt[l]++;
  }
  int left=0, right=1e6;
  while(right-left>1){
    int mid=(left+right)/2;
    int now=0;
    for(auto& [_, x]:cnt) now+=min(x, mid);
    if(now>=3*mid) left=mid;
    else right=mid;
  }
  cout << left << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}