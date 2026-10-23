#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 整数, 最小公倍数

ll modpow(ll a, ll b, ll p){
  a%=p;
  ll ans=1;
  while(b>0){
    if(b%2==1) ans=(ans*a)%p;
    b/=2;
    a=(a*a)%p;
  }
  return ans;
}

int main(void){
  int n; cin >> n;
  vector<int> a(n), mx(1e6+1);
  for(auto&x:a) cin >> x;
  sort(begin(a), end(a));
  int nn=1e6+1;
  vector<int> yakusu(nn+1, -1), prime;
  for(int i=2; i<=nn; i++){
    if(yakusu[i]!=-1) continue;
    int copy=i;
    prime.push_back(i);
    while(copy<=nn){
      if(yakusu[copy]==-1) yakusu[copy]=i;
      copy+=i;
    }
  }
  for(int i=0; i<n; i++){
    int x=a[i];
    while(x>1){
      int d=yakusu[x], c=0;
      while(x%d==0) c++, x/=d;
      mx[d]=max(mx[d], c);
    }
  }
  ll ans=1, mod=1e9+7;
  for(auto p:prime)if(mx[p]) ans*=modpow(p, mx[p], mod), ans%=mod;
  ans*=modpow(a[0], mod-2, mod), ans%=mod;
  cout << ans << endl;
  return 0; 
}