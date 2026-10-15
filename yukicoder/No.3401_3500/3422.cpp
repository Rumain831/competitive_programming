#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 二分探索
//Level: 2

int main(void){
  ll n, m; cin >> n >> m; 
  vector<ll> day;
  for(int i=0; i<n; i++){
    ll a, b; cin >> a >> b;
    ll x=(m-a+b-1)/b; 
    if(a+x*b==m) x++;
    day.push_back(x);
  }
  sort(begin(day), end(day));
  int left=0, right=n;
  auto judge=[&](int x){
    if(x==0) return false;
    int r=x-1, c=1;
    while(r<n){
      if(day[r]<c) return false;
      if(r==n-1) break;
      if(day[r+1]<=c) return false;
      r+=x;
      r=min<int>(r, n-1); c++;
    }
    return true;
  };
  while(right-left>1){
    int mid=(left+right)/2;
    if(judge(mid)) right=mid;
    else left=mid;
  }
  cout << right << endl;
  return 0; 
}