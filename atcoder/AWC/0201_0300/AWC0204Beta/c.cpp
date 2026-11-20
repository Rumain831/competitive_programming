#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: Simulation

int main(void){
  int n; cin >> n;
  vector<ll> cnt(1e5+1);
  ll sum=0;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    cnt[a]++, sum+=a;
  }
  int q; cin >> q;
  while(q--){
    int b, c; cin >> b >> c;
    sum-=b*cnt[b];
    sum+=c*cnt[b];
    cnt[c]+=cnt[b], cnt[b]=0;
    cout << sum << '\n';
  }
  return 0; 
}