#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 漸化式
//Level: 2.5

int main(void){
  ll n, p; cin >> n >> p;
  ll ans=0, sum=0, mod=1e9+7;
  vector<ll> a(n+2);
  a[0]=0, a[1]=1;
  for(int i=0; i<n; i++){
    sum+=a[i], sum%=mod;
    ans+=a[i]*sum%mod, ans%=mod;
    if(i) a[i+1]=(p*a[i]%mod+a[i-1])%mod;
  }
  cout << ans << endl;
  return 0; 
}