#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

ll MOD=998244353;
vector<ll> INV{0, 1};
ll modpow(ll a, ll b, ll p){
  ll ans=1;
  while(b>0){
    if(b%2==1) ans=(ans*a)%p;
    b/=2;
    a=(a*a)%p;
  }
  return ans;
}
void calc_inv(int n){
  int now=(int)INV.size()-1;
  if(n<=now) return;
  INV.resize(n+1);
  for(int i=now+1; i<=n; i++) INV[i]=modpow(i, MOD-2, MOD);
}

void ntt(vector<ll>& a, bool inv){
  int n=(int)a.size();
  ll mod=998244353, g=3; //gはmodの原始根
  //bit-reverse permutation
  for(int i=1, j=0; i<n; i++){
    int bit=n>>1;
    for(; j&bit; bit>>=1) j^=bit;
    j^=bit;
    if(i<j) swap(a[i], a[j]);
  }
  //iterative Cooley–Tukey
  for(int len=2; len<=n; len<<=1){
    ll wlen=modpow(g, (mod-1)/len, mod);
    if(inv) wlen=modpow(g,(mod-1)-(mod-1)/len, mod); // inv root
    for(int i=0; i<n; i+=len){
      ll w=1;
      int half=len>>1;
      for(int j=0; j<half; j++){
        ll u=a[i+j];
        ll v=(ll)((__int128)a[i+j+half]*w%mod);
        a[i+j]=u+v; if(a[i+j]>=mod) a[i+j]-=mod;
        a[i+j+half]=u-v; if(a[i+j+half]<0) a[i+j+half]+=mod;
        w=(ll)((__int128)w*wlen%mod);
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

struct Pol{
  vector<ll> a;
  Pol(){}
  Pol(int n):a(n, 0){}
  Pol(const vector<ll>& co):a(co){trim();}
  int size()const{return a.size();}
  void resize(int n){a.resize(n, 0);}
  void trim(){while(a.size()&&a.back()==0) a.pop_back();}
  
  ll& operator[](int i){return a[i];}
  const ll& operator[](int i)const{return a[i];}

  Pol& operator+=(const Pol& r){
    int p=size(), q=r.size();
    if(p<q) resize(q);
    for(int i=0; i<q; i++){
      a[i]+=r.a[i];
      if(a[i]>=MOD) a[i]-=MOD;
    }
    return *this;
  }
  Pol& operator-=(const Pol& r){
    int p=size(), q=r.size();
    if(p<q) resize(q);
    for(int i=0; i<q; i++){
      a[i]-=r.a[i];
      if(a[i]<0) a[i]+=MOD;
    }
    trim();
    return *this;
  }
  Pol& operator*=(const Pol& r){
    a=convolution(a, r.a);
    return *this;
  }
  friend Pol operator+(Pol l, const Pol& r){l+=r; return l;}
  friend Pol operator-(Pol l, const Pol& r){l-=r; return l;}
  friend Pol operator*(Pol l, const Pol& r){l*=r; return l;}
};

Pol cut(const Pol& f, int n){Pol g=f; if(g.size()>n) g.resize(n); return g;} //n次でcut
Pol shiftk(const Pol& f, int k){Pol g(k+f.size()); for(int i=0; i<f.size(); i++) g.a[i+k]=f.a[i]; return g;}
Pol& scale_c(Pol& f, ll c){c%=MOD; c=(c+MOD)%MOD; for(auto&x:f.a)x=(x*c)%MOD; return f;} 
int ord(const Pol& F){
  for(int i=0; i<F.size(); i++)if(F.a[i]) return i;
  return F.size()+1;
}

Pol invPol(const Pol& F, int n){
  //assert(!F.a.empty()&&F.a[0]%MOD!=0);
  Pol G(1); G.a[0]=modpow(F.a[0], MOD-2, MOD);
  for(int m=1; m<n; m<<=1){
    int M=min(n, m<<1);
    Pol Fm=cut(F, M);
    Pol T; T.a=convolution(G.a, Fm.a); T.resize(M);
    if(T.a.empty()) T.a.resize(1, 0);
    T.a[0]=(MOD+2-T.a[0])%MOD;
    for(int i=1; i<M; i++) T.a[i]=(MOD-T.a[i])%MOD;  
    G.a=convolution(G.a, T.a);
    G.resize(M); 
  }
  G.resize(n);
  return G;
}

Pol deriv(const Pol& f){
  if(f.size()==0) return Pol();
  Pol ans(max(0, f.size()-1));
  for(int i=1; i<f.size(); i++){
    ans.a[i-1]=(f.a[i]*(ll)i)%MOD;
  }
  return ans;
}

Pol integPol(const Pol& f){
  calc_inv(f.size()+1);
  Pol g(f.size()+1);
  g.a[0]=0;
  for(int i=0; i<f.size(); i++){
    g.a[i+1]=(f.a[i]*INV[i+1])%MOD;
  }
  return g;
}

Pol logPol(const Pol& F, int n){ //F'/Fの積分
  //assert(F.size() && F.a[0] % MOD == 1); F[0]=1が必要
  Pol dF=deriv(F);
  Pol invF=invPol(F, n);
  Pol Q; Q.a=convolution(dF.a, invF.a);
  Q.resize(max(0, n-1));
  Pol L=integPol(Q);
  L.resize(n);
  return L;
}

Pol expPol(const Pol& f, int n){
  //assert(F.a.empty()||F.a[0]!=0);
  Pol F=cut(f, n);
  if(n==0) return Pol();
  Pol G(1); G.a[0]=1;
  //ニュートン法らしい
  for(int m=1; m<n; m<<=1){
    int M=min(n, m<<1);
    Pol Gcut=cut(G, M);
    Pol L=logPol(Gcut, M); L.resize(M);
    Pol Fm=cut(F, M); Fm.resize(M);
    for(int i=0; i<M; i++){
      L.a[i]=(Fm.a[i]-L.a[i])%MOD;
      if(L.a[i]<0) L.a[i]+=MOD;
    }
    L.a[0]=(L.a[0]+1)%MOD;
    G.a=convolution(G.a, L.a);
    G.resize(M); 
  }
  G.resize(n);
  return G;
}

Pol powPol(Pol f, ll k, int n){ //exp(klogf)
  if(n==0) return Pol();
  if(k==0){Pol I(n); I.a[0]=1; return I;}
  int v=ord(f);
  if(v>f.size()) return Pol(n);
  __int128_t shift=v*k;
  if(shift>=n) return Pol(n);
  ll need=n-shift;
  if(v){f.a.erase(f.a.begin(), f.a.begin()+v);}
  //x^v f 
  ll a0=f.a[0], inva0=modpow(a0, MOD-2, MOD);
  //x^v a0 f -> 答えは x^vk a0^k exp(klogf)
  for(auto&x:f.a) x=(x*inva0)%MOD;
  Pol L=logPol(f, need);
  L=scale_c(L, k%MOD);
  Pol U=expPol(L, need);
  U=scale_c(U, modpow(a0, k, MOD));
  U=shiftk(U, shift);
  U.resize(n);
  return U;
}