#include<iostream>
using namespace std;
using ll = long long;

//Tags: 整数, 最大公約数

int main(void){
  int n; cin >> n;
  ll c[30]={};
  ll sum=0, ans=0;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    int d=0;
    while(x&&x%2==0) d++, x/=2;
    c[d]++;
  }
  sum=n;
  for(int i=0; i<30; i++){
    ll x=c[i];
    sum-=x;
    ans+=x*(x-1)/2*sum;
  }
  cout << ans << endl;
  return 0; 
}