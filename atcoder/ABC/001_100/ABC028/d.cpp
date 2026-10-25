#include<iostream>
using namespace std;
using ll = long long;

//Tags: 確率

int main(void){
  ll n, k; cin >> n >> k;
  ll ans=1;
  ans+=3ll*(n-1);
  ans+=6ll*(k-1)*(n-k);
  printf("%.10f\n", (double)ans/(n*n*n));
  return 0; 
}