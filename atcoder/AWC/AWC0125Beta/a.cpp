#include<iostream>
using namespace std;
using ll = long long;

//Tags: 考察で瞬殺

int main(void){
  ll n, d, s; cin >> n >> d >> s;
  ll sum=0;
  for(int i=0; i<n; i++){
    ll t; cin >> t; sum+=t;
  }
  cout << sum+min(abs(s-1)*d, abs(n-s)*d)+(n-1)*d << endl;
  return 0; 
}