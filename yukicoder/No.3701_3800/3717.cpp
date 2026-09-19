#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 整数, 最大公約数, 最小公倍数
//Level: 2.5

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
  int nn=1e6;
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
  int n, k; cin >> n >> k;
  map<int, vector<int>> cnt;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    while(a>1){
      int d=yakusu[a], c=0;
      while(a%d==0) c++, a/=d;
      cnt[d].push_back(c);
    }
  }
  ll ans=1, mod=998244353, tar=n/k;
  for(auto&[d, vec]:cnt){
    sort(begin(vec), end(vec));
    int t=vec.size(), zero=n-t;
    int p=(tar<=zero?0:vec[tar-zero-1]);
    ans*=modpow(d, p, mod), ans%=mod;
  }
  cout << ans << endl;
  return 0; 
}