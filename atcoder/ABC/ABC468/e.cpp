#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 主客転倒, imos法

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


int main(void){
  int n; cin >> n;
  vector<mint> a(n), inv(n+1);
  for(auto&x:a) cin >> x;
  for(int i=1; i<=n; i++) inv[i]=mint(1)/i;
  vector<mint> imos(n+2);
  auto put=[&](mint x){
    imos[0]+=inv[x.val];
    imos[x.val]-=inv[x.val];
    imos[n-x.val+1]-=inv[x.val];
  };
  for(int i=1; i<=n; i++){
    put(i);
  }
  for(int i=1; i<=n; i++) imos[i]+=imos[i-1];
  for(int i=1; i<=n; i++) imos[i]+=imos[i-1];
  mint ans=0;
  for(int i=0; i<n; i++) ans+=a[i]*imos[i];
  cout << ans << endl;
  return 0; 
}