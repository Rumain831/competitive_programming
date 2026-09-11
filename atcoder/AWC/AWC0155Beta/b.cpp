#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: Simulation

int main(void){
  ll n, d, s; cin >> n >> d >> s; s--;
  vector<ll> a(n);
  ll sum=0;
  for(auto&x:a) cin >> x, sum+=x;
  d--;
  ll roop=d/n, r=d%n;
  ll ans=roop*sum;
  for(int i=0; i<=r; i++){
    int ni=(s+i)%n;
    ans+=a[ni];
  }
  cout << ans << endl;
  return 0; 
}