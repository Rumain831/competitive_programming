#include<iostream>
using namespace std;
using ll = long long;

//Tags: メビウス関数
//Level: 1.5

int mu_naive(ll n){
  if(n==1) return 1;
  int ans=1;
  for(ll i=2; i*i<=n; i++){
    if(n%i) continue;
    int c=0;
    while(n%i==0){
      c++, n/=i;
    }
    if(c>=2) return 0;
    ans*=-1;
  }
  if(n>1) ans*=-1;
  return ans;
}

int main(void){
  ll n; cin >> n;
  cout << mu_naive(n) << endl;
  return 0; 
}