#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

ll MOD=998244353;
ll modpow(ll a, ll b, ll p){
  ll ans=1;
  while(b>0){
    if(b%2==1) ans=(ans*a)%p;
    b/=2;
    a=(a*a)%p;
  }
  return ans;
}

vector<ll> ntt(const vector<ll>& a, int inv){
  ll g=3; //998244353の原始根
  ll mod=998244353;
  int n=a.size();
  if(n==0) return {};
  if(n==1) return a;
  vector<ll> ao(n/2), ae(n/2), ans(n);
  for(int i=0; i<n; i+=2) ae[i/2]=a[i], ao[i/2]=a[i+1];
  vector<ll> odd=ntt(ao, inv); 
  vector<ll> even=ntt(ae, inv);
  ll omega_n=modpow(g, (mod-1)/n, mod);  //998244352=2^23*7*17
  if(inv==-1) omega_n=modpow(omega_n, mod-2, mod);
  ll omega=1;
  for(int i=0; i<n/2; i++){
    ans[i]=even[i]+omega*odd[i]; ans[i]%=mod;
    ans[i+n/2]=even[i]-omega*odd[i]%mod+mod;
    ans[i+n/2]%=mod;
    omega*=omega_n, omega%=mod;
  }
  return ans; 
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
  vector<ll> da=ntt(a, 1);
  vector<ll> db=ntt(b, 1);
  vector<ll> dc(n);
  for(int i=0; i<n; i++) dc[i]=da[i]*db[i], dc[i]%=mod;
  vector<ll> c=ntt(dc, -1);
  ll n_inv=modpow(n, mod-2, mod);
  vector<ll> ans;
  for(int i=0; i<lc; i++){
    ans.push_back(c[i]*n_inv%mod);
  }
  return ans;
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