#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 考察
//Level: 2

int main(void){
  int n; cin >> n;
  vector<ll> a(n);
  ll sq=0, sum=0;
  for(auto&x:a) cin >> x, sum+=x, sq+=x*x;
  cout << (sum*sum-sq)/2 << endl;
  return 0; 
}