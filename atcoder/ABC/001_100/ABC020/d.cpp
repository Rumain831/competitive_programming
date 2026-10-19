#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 整数, 高速メビウス変換, 最小公倍数

const ll MOD=1e9+7;

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
  ll n, k; cin >> n >> k;
  vector<ll> g, prime;
  for(ll i=1; i*i<=k; i++){
    if(k%i) continue;
    g.push_back(i);
    if(i!=k/i) g.push_back(k/i);
  }
  {
    ll x=k;
    for(ll i=2; i*i<=k; i++){
      if(x%i) continue;
      prime.push_back(i);
      while(x%i==0) x/=i;
    }
    if(x>1) prime.push_back(x);
  }
  sort(begin(g), end(g));
  map<ll, mint> f;
  mint inv2=mint(1)/2;
  for(auto x:g){
    mint cnt=n/x;
    mint now=inv2*cnt*(x+x+x*(cnt-1));
    f[x]=now;
  }
  for(auto p:prime){
    for(auto x:g){
      if(x%p) continue;
      f[x/p]-=f[x];
    }
  }
  mint ans=0;
  for(auto x:g) ans+=f[x]/x*k;
  cout << ans << endl;
  return 0; 
}