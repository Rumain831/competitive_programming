#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 実装
//Level: 2

ll mid(vector<ll>& a){
  int n=a.size();
  if(n&1) return a[n/2];
  else return (a[n/2-1]+a[n/2])/2;
}

int main(void){
  int n; cin >> n;
  vector<ll> a(n), pre, aft;
  for(auto&x:a) cin >> x, x*=2;
  sort(begin(a), end(a));
  pre.insert(end(pre), begin(a), begin(a)+n/2);
  aft.insert(end(aft), end(a)-n/2, end(a));
  ll q1=mid(pre), q2=mid(a), q3=mid(aft), I=q3-q1;
  int u=0;
  for(auto x:a) u+=((x*2<q1*2-I*3)||(q3*2+I*3<x*2));
  printf("%.1f %.1f %.1f %d\n", (double)q1/2.0, (double)q2/2.0, (double)q3/2.0, u);
  return 0;
}