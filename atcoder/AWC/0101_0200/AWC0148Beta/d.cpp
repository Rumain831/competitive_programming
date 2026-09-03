#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 貪欲法

int main(void){
  ll n, p; cin >> n >> p;
  vector<ll> lim(n);
  for(int i=0; i<n; i++){
    ll h, g; cin >> h >> g; 
    if(h>p){
      lim[i]=-1; continue;
    }
    ll x=p-h;
    //gt>x
    lim[i]=(x%g?(x+g-1)/g:x/g+1);
  }
  sort(begin(lim), end(lim));
  for(int i=0; i<n; i++){
    if(lim[i]<=i){
      cout << "No" << endl; return 0;
    }
  }
  cout << "Yes" << endl;
  return 0; 
}