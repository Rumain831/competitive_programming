#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 数え上げ, 主客転倒, 順列

const ll MOD=998244353;

struct mint{
  ll val;
  mint(ll val_=0):val(val_%MOD){
    if(val<0) val+=MOD; 
  }

  mint operator-()const{
    return mint(-val);
  }
  mint& operator+=(const mint& other){
    val+=other.val;
    if(val>=MOD) val-=MOD;
    return *this;
  }
  mint& operator-=(const mint& other){
    val-=other.val;
    if(val<0) val+=MOD;
    return *this;
  }
  mint& operator*=(const mint& other){
    val*=other.val, val%=MOD;
    return *this;
  }
  mint pow(ll n) const{
    mint ans(1);
    mint mul(*this);
    while(n){
      if(n&1) ans*=mul;
      mul*=mul;
      n/=2;
    }
    return ans;
  }
  mint inv() const{
    return pow(MOD-2);
  }
  mint& operator/=(const mint& other){
    return *this*=other.inv();
  }

  friend bool operator==(const mint& lhs, const mint& rhs){
    return lhs.val == rhs.val;
  }
  friend bool operator!=(const mint& lhs, const mint& rhs){
    return lhs.val != rhs.val;
  }
  friend mint operator+(mint lhs, const mint& rhs) {
    lhs+=rhs;
    return lhs;
  }
  friend mint operator-(mint lhs, const mint& rhs) {
    lhs-=rhs;
    return lhs;
  }
  friend mint operator*(mint lhs, const mint& rhs) {
    lhs*=rhs;
    return lhs;
  }
  friend mint operator/(mint lhs, const mint& rhs) {
    lhs/=rhs;
    return lhs;
  }
  friend istream& operator>>(istream& is, mint& m) {
    ll x;
    is >> x;
    m=mint(x);
    return is;
  }
  friend ostream& operator<<(ostream& os, const mint& m) {
    return os << m.val;
  }
};

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

pair<vector<mint>, vector<mint>> factorial(int n){
  vector<mint> fact(n+1, 1), invfact(n+1, 1);
  for(ll i=2; i<=n; i++) fact[i]=fact[i-1]*i;
  invfact[n]=modpow(fact[n].val, MOD-2, MOD);
  for(ll i=n-1; i>=1; i--) invfact[i]=invfact[i+1]*(i+1);
  return {fact, invfact};
}

ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}

int main(void){
  int n, k; cin >> n >> k;
  auto [fact, rev]=factorial(n+10);
  mint ans=0;
  auto dfs=[&](auto dfs, int now, int last, vector<int>& p)->void {
    if(now==n){
      int d=p.size();
      int m=n;
      mint now=1;
      ll lcm=p[0];
      vector<int> cnt(n+1);
      for(int i=0; i<d; i++){
        now*=fact[m]*rev[p[i]]*rev[m-p[i]]*fact[p[i]-1];
        now*=fact[cnt[p[i]]]*rev[cnt[p[i]]+1]; cnt[p[i]]++;
        m-=p[i];
        ll g=gcd(lcm, p[i]);
        lcm=lcm/g*p[i];
      }
      lcm%=MOD;
      ll x=modpow(lcm, k, MOD);
      ans+=(now*x); return;
    }
    for(int i=max(1, last); now+i<=n; i++){
      p.push_back(i);
      dfs(dfs, now+i, i, p);
      p.pop_back();
    }
    return;
  };
  vector<int> vec={};
  dfs(dfs, 0, 0, vec);
  cout << ans << endl;
  return 0; 
}