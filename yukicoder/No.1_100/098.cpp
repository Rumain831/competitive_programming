#include<iostream>
using namespace std;
using ll = long long;

//Tags: 幾何

int main(void){
  ll x, y; cin >> x >> y;
  ll d=x*x+y*y;
  ll left=0, right=1e9+1;
  while(right-left>1){
    ll mid=(left+right)/2;
    if(mid*mid>d*4) right=mid;
    else left=mid;
  }
  cout << right << endl;
  return 0; 
}