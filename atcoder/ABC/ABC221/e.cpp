#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: dp

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

template<class Tr=mint>
struct BIT{
  int n;
  vector<Tr> bit;
  BIT(int size): n(size), bit(size+1, 0) {};

  void add(int i, Tr x){ //1-indexed
    while(i<=n){
      bit[i]+=x;
      i+=i&-i;
    }
  }

  Tr sum(int i){ //1-indexed
    Tr ans=0;
    while(i>0){
      ans+=bit[i];
      i-=i&-i;
    }
    return ans;
  }

  Tr range(int l, int r){ //1-indexed
    return sum(r)-sum(l-1);
  }
};

int main(void){
  int n; cin >> n;
  vector<int> a(n), cc(n);
  {
    //座標圧縮
    map<int, int> mp, id;
    for(auto&x:a) cin >> x, mp[x]++;
    int c=0;
    for(auto [x, _]:mp) id[x]=++c;
    for(int i=0; i<n; i++) cc[i]=id[a[i]];
  }
  int m=cc.size();
  BIT bit(m); 
  bit.add(cc[0], 1);
  vector<mint> two(n, 1), inv(n);
  for(int i=1; i<n; i++) two[i]=two[i-1]*2;
  inv[n-1]=mint(1)/two[n-1];
  for(int i=n-2; i>=0; i--) inv[i]=inv[i+1]*2;
  mint ans=0;
  for(int i=1; i<n; i++){
    ans+=bit.range(1, cc[i])*two[i-1];
    bit.add(cc[i], inv[i]);
  }
  cout << ans << endl;
  return 0; 
}