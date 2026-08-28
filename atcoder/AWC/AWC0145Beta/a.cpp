#include<iostream>
using namespace std;
using ll = long long;

//Tags: 四則演算

int main(void){
  ll n, m, p; cin >> n >> m >> p;
  ll sum=0;
  while(n--){
    ll d, v; cin >> d >> v;
    if(d<=m) sum+=v;
  }
  cout << (sum*100-sum*p)/100 << endl;
  return 0; 
}