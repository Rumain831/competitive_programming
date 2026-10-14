#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

ll modpow(ll a, ll b, ll p){
  ll ans=1;
  while(b>0){
    if(b%2==1) ans=(ans*a)%p;
    b/=2;
    a=(a*a)%p;
  }
  return ans;
}

vector<ll> roots{0,1}, iroots{0,1}; // index 0はダミー、1を必ず用意
void calc_roots(int n){
  static const ll mod=998244353, g=3;
  if((int)roots.size() >= n) return;
  int k = __builtin_ctz((int)roots.size());     // 2,4,8,... から拡張
  roots.resize(n);
  iroots.resize(n);
  while((1<<k) < n){
    // 段 k の原始根
    ll z  = modpow(g, (mod-1)>>(k+1), mod);
    ll iz = modpow(z, mod-2, mod);
    int start = 1<<k;        // この段で新たに埋める範囲
    int mid   = start<<1;
    // 直前段の [start/2 .. start) を参照してコピー＆掛け算で埋める
    for(int i=start; i<mid; ++i){
      roots[i]  = (i&1)? (ll)((__int128)roots[i>>1]*z  % mod) : roots[i>>1];
      iroots[i] = (i&1)? (ll)((__int128)iroots[i>>1]*iz % mod) : iroots[i>>1];
    }
    ++k;
  }
}

void ntt(vector<ll>& a, bool inv){
  if (a.empty()) return;
  int n=(int)a.size();
  ll mod=998244353, g=3; //gはmodの原始根
  calc_roots(n);
  //bit-reverse permutation
  for(int i=1, j=0; i<n; i++){
    int bit=n>>1;
    for(; j&bit; bit>>=1) j^=bit;
    j^=bit;
    if(i<j) swap(a[i], a[j]);
  }
  //iterative Cooley–Tukey
  for(int len=1; len<n; len<<=1){
    //lenはバタフライの半分長(段指数)
    for(int i=0; i<n; i+= (len<<1)){
      for(int j=0; j<len; j++){
        ll w = (inv? iroots[len+j] : roots[len+j]);
        ll u = a[i+j];
        ll v = (ll)((__int128)a[i+j+len] * w % mod);
        a[i+j]      = u + v; if(a[i+j]      >= mod) a[i+j]      -= mod;
        a[i+j+len]  = u - v; if(a[i+j+len]  <  0)  a[i+j+len]  += mod;
      }
    }
  }
  if(inv){
    ll inv_n=modpow(n, mod-2, mod);
    for(auto& x : a) x = (ll)((__int128)x * inv_n % mod);
  }
}

vector<ll> convolution(const vector<ll>& A, const vector<ll>& B){
  ll mod=998244353;
  vector<ll> a=A, b=B;
  int la=a.size(), lb=b.size();
  if(la==0||lb==0) return {};
  int lc=la+lb-1; // len_c は A(x) * B(x) の次数
  int n=1;
  while(n<lc) n*=2;  
  a.resize(n);
  b.resize(n);
  ntt(a, false);
  ntt(b, false);
  for(int i=0; i<n; i++) a[i]=a[i]*b[i], a[i]%=mod;
  ntt(a, true);
  a.resize(lc);
  return a;
}
