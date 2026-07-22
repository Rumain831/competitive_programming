#include<iostream>
using namespace std;
using ll = long long;

int main(void){
  ll n; cin >> n;
  ll ans=0;
  for(ll a=1; a*a*a<=n; a++){
    for(ll b=a; a*b*b<=n; b++){
      ll p=n/(a*b);
      if(b<=p) ans+=p-b+1;
    }
  }
  cout << ans << endl;
  return 0; 
}