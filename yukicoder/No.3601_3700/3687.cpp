#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 最小公約数
//Level: 3.5

int main(void){
  ll n, m; cin >> n >> m;
  ll x=min(m, n);
  vector<ll> cnt(x+1);
  for(int i=1; i<=x; i++){
    cnt[i]=(n/i)*(m/i);
  }
  for(int i=x-1; i>=1; i--){
    int now=i+i;
    while(now<=x){
      cnt[i]-=cnt[now];
      now+=i;
    }
  }
  cout << cnt[1] << endl;
  return 0; 
}