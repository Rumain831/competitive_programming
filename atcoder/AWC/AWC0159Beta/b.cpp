#include<iostream>
#include<map>
using namespace std;
using ll = long long;

//Tags: 数え上げ

int main(void){
  int n, k; cin >> n >> k;
  map<int, ll> cnt;
  ll ans=0;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    ans+=cnt[a-k];
    ans+=cnt[a+k];
    cnt[a]++;
  }
  cout << ans << endl;
  return 0; 
}