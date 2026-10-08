#include<iostream>
#include<map>
using namespace std;
using ll = long long;

//Tags: 数え上げ

int main(void){
  int n, k; cin >> n >> k;
  ll ans=0;
  map<int, ll> cnt;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    ans+=cnt[k-x];
    cnt[x]++;
  }
  cout << ans << endl;
  return 0; 
}