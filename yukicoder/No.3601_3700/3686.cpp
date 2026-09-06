#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 整数
//Level: 3.5

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
  ll n, m; cin >> n >> m;
  ll x=min(n, m);
  vector<mint> sn(x+1), sm(x+1);
  for(int i=1; i<=x; i++){
    int now=i;
    while(now<=n){
      sn[i]+=now;
      now+=i;
    }
    now=i;
    while(now<=m){
      sm[i]+=now;
      now+=i;
    }
  }
  vector<mint> sum(x+1);
  for(int i=1; i<=x; i++) sum[i]=sn[i]*sm[i];
  for(int i=x-1; i>=1; i--){
    int now=i+i;
    while(now<=x){
      sum[i]-=sum[now];
      now+=i;
    }
  }
  cout << sum[1] << endl;
  return 0; 
}