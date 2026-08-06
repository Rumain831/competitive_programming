#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: MEX
//https://codeforces.com/contest/2185/problem/C
//x, x+1, ..., x+l-1 が全てaの中にあるような最大の正整数lが答え

void solve(){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  sort(begin(a), end(a));
  int mx=0, l=0, r=-1;
  a.erase(unique(begin(a), end(a)), end(a));
  n=a.size();
  while(l<n){
    if(r<l) r=l;
    int now=a[l];
    while(r<n){
      if(now!=a[r]) break;
      now++, r++;
    }
    mx=max(mx, r-l);
    l=r;
  }
  cout << mx << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}