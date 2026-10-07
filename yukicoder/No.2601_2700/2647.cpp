#include<iostream>
using namespace std;
using ull = unsigned long long;

//Tags: 四則演算, 四捨五入
//Level: 1

void solve(){
  int d; ull a; cin >> d >> a;
  while(d--){
    ull x; cin >> x; x*=10;
    x/=a;
    int p=x%10;
    x/=10;
    if(p>=5) x++; 
    cout << x << ' ';
  }
  cout << endl;
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}