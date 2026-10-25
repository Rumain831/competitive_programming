#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;

//Tags: grid

int main(void){
  int r, c, k; cin >> r >> c >> k;
  int n; cin >> n;
  vector<ll> tater(r), yokoc(c), R(n), C(n);
  for(int i=0; i<n; i++){
    int rr, cc; cin >> rr >> cc; rr--, cc--;
    tater[rr]++; yokoc[cc]++;
    R[i]=rr, C[i]=cc;
  }
  map<ll, ll> tate, yoko;
  for(int i=0; i<r; i++) tate[tater[i]]++;
  for(int i=0; i<c; i++) yoko[yokoc[i]]++;
  ll ans=0;
  for(auto p:tate){
    auto [ame, hist]=p;
    ans+=hist*yoko[k-ame];
  }
  for(int i=0; i<n; i++){
    int ni=R[i], nj=C[i];
    if(tater[ni]+yokoc[nj]==k) ans--;
    else if(tater[ni]+yokoc[nj]==k+1) ans++;
  }
  cout << ans << endl;
  return 0;
}