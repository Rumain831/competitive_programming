#include<iostream>
#include<unordered_set>
using namespace std;
using ll = long long;

//Tags: 整数, 全探索
//Level: 2

int main(void){
  ll n, p; cin >> n >> p;
  ll ans=0;
  unordered_set<int> used;
  for(int i=1; i<10; i++)for(int j=0; j<10; j++)for(int k=0; k<10; k++){
    ll now=i*110000+j*1001+k*110;
    ll x=now;
    while(x<=n){
      if(used.count(x)){x+=now; continue;}
      ans+=-x, ans%=p; ans=(ans+p)%p;
      used.insert(x);
      x+=now;
    }
  }
  cout << ans << endl;
  return 0; 
}