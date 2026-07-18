#include<iostream>
using namespace std;
using ll = long long;

int main(void){
  ll n, k, t; cin >> n >> k >> t;
  ll sum=0;
  for(int i=0; i<n; i++){
    ll d, r; cin >> d >> r;
    if(r>=k*d) sum+=r;
  }
  cout << (sum>=t?"Yes":"No") << endl;
  return 0;
}