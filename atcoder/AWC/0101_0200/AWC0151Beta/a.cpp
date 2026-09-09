#include<iostream>
using namespace std;
using ll = long long;

//Tags: 条件分岐

int main(void){
  ll n, m, k; cin >> n >> m >> k;
  ll sum=0;
  for(int i=0; i<m; i++){
    ll a; cin >> a;
    sum+=a;
  }
  cout << (sum<=n*k?"Yes":"No") << endl;
  return 0; 
}