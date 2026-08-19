#include<iostream>
using namespace std;
using ll = long long;

//Tags: 考察

int main(void){
  int n; cin >> n;
  ll ans=0;
  for(int i=1; i<n; i++){
    ll b; cin >> b;
    ans+=b*i;
  }
  cout << ans << endl;
  return 0; 
}