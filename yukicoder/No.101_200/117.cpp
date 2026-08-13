#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 場合の数

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

pair<vector<ll>, vector<ll>> factorial(int n, ll mod){
  vector<ll> fact(n+1, 1), invfact(n+1, 1);
  for(ll i=2; i<=n; i++) fact[i]=fact[i-1]*i%mod;
  invfact[n]=modpow(fact[n], mod-2, mod);
  for(ll i=n-1; i>=1; i--) invfact[i]=invfact[i+1]*(i+1)%mod;
  return {fact, invfact};
}

pair<int, int> f(string& s){
  int n=s.size();
  int co;
  for(int i=0; i<n; i++)if(s[i]==','){co=i; break;}
  int a=stoi(s.substr(0, co)), b=stoi(s.substr(co+1, n-co-1));
  return {a, b};
}

int main(void){
  int q; cin >> q;
  ll mod=1e9+7;
  auto [fact, inv]=factorial(2e6+1, mod);
  auto nCk=[&](int n, int k){
    if(k>n) return 0ll;
    return fact[n]*inv[k]%mod*inv[n-k]%mod; 
  };
  while(q--){
    string s; cin >> s;
    int t;
    if(s[0]=='P') t=0;
    else t=(s[0]=='C'?1:2);
    int l, r;
    for(int i=0; i<s.size(); i++){
      if(s[i]=='(') l=i;
      if(s[i]==')') r=i;
    }
    l++;
    string T=s.substr(l, r-l);
    auto [a, b]=f(T);
    if(t==0) cout << nCk(a, b)*fact[b]%mod << '\n';
    else if(t==1) cout << nCk(a, b) << '\n';
    else{
      if(a==0){
        cout << (b==0?1:0) << '\n';
      }
      else cout << nCk(a+b-1, b) << '\n';
    }
  }
  return 0; 
}