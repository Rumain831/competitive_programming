#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 貪欲法

int main(void){
  int n; cin >> n;
  ll sum=0;
  vector<ll> a(n);
  for(auto&x:a) cin >> x, sum+=x;
  sort(rbegin(a), rend(a));
  ll now=0, tar=(sum+1)/2;
  for(int i=0; i<n; i++){
    now+=a[i];
    if(now>=tar){
      cout << i+1 << endl; return 0;
    }
  }
  return 0; 
}