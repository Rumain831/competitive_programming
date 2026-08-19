#include<iostream>
using namespace std;
using ll = long long;

//Tags: 平均

int main(void){
  ll n, k; cin >> n >> k;
  ll sum=0, cnt=0;
  for(int i=0; i<n; i++){
    ll s; cin >> s;
    if(s>=k) cnt++, sum+=s;
  }
  if(cnt==0){
    cout << -1 << endl; return 0;
  }
  printf("%.10f\n", (double)sum/cnt);
  return 0; 
}