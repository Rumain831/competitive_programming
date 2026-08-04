#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 貪欲法

int main(void){
  ll n, m, k; cin >> n >> m >> k;
  vector<ll> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  ll cnt=0, now=0, id=0;
  while(id<n){
    if(a[id]>k){
      cout << "Yes" << endl; return 0;
    }
    while(id<n){
      if(now+a[id]>k){
        cnt++, now=0; break;
      }
      else now+=a[id], id++;
    }
  }
  cnt++;
  cout << (cnt<=m?"No":"Yes") << endl;
  return 0; 
}