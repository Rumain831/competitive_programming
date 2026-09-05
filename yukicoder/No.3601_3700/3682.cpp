#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 確率, 漸化式
//Level: 2.5

const ll MOD=998244353;

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

void solve(){
  vector<ll> c(3);
  vector<ll> g(3);
  for(auto&x:c) cin >> x;
  for(auto&x:g) cin >> x;
  ll nx=(c[0]+g[1]-1)/g[1], ny=(g[0]+c[1]-1)/c[1];
  ll d=min(nx, ny)-1;
  nx-=d, ny-=d;
  mint ten=mint(1)/10;
  if(c[2]!=g[2]){
    bool rev=false;
    if(c[2]<g[2]){
      rev=true;
      swap(nx, ny);
      swap(c[0], g[0]);
    }
    mint ans;
    if(ny>=2){
      ans=(nx==0?0:mint(1)/11*modpow(ten.val, ny-2, MOD));
    }
    else if(ny==1){
      ans=(nx==0?0:mint(1)-mint(1)/11*modpow(ten.val, nx-1, MOD));
    }
    else ans=1;
    if(rev) ans=mint(1)-ans;
    cout << ans << '\n';
  }
  else{
    bool rev=false;
    if(nx>ny) swap(nx, ny), rev=true;
    mint ans;
    if(nx==0) ans=0;
    else{
      ans=mint(1)/2*modpow(ten.val, ny-1, MOD);
    }
    if(rev) ans=mint(1)-ans;
    cout << ans << '\n';
  }
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}