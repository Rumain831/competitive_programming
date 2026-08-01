#include <iostream>
using namespace std;
using ll = long long;

//Tags: bit演算

int main(){
  int t; cin >> t;
  while(t--){
    ll a, s; cin >> a >> s;
    if(s>=2*a&&((s-2*a)&a)==0) cout << "Yes" << '\n';
    else cout << "No" << endl;
  }
  return 0;
}