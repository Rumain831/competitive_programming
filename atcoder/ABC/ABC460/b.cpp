#include<iostream>
using namespace std;
using ll = long long;

ll sq(ll a, ll b){return a*a+b*b;}

void solve(){
  ll x1, y1, r1, x2, y2, r2; cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  ll d=sq(x1-x2, y1-y2);
  if(abs(r1-r2)*abs(r1-r2)<=d&&d<=sq(r1+r2, 0)) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}