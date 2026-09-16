#include<iostream>
using namespace std;
using ll = long long;

//Tags: 整数, 全探索
//Level: 2
//Nが偶数のとき...などと場合分けするのも面倒なので、約数が3以上ならminをとる、で済ませば楽

int main(void){
  ll n; cin >> n;
  ll ans=n;
  for(ll i=1; i*i<=n; i++)if(n%i==0){
    if(i>2) ans=min(ans, i);
    if(n/i>2) ans=min(ans, n/i);
  }
  cout << ans << endl;
  return 0; 
}