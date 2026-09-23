#include<iostream>
using namespace std;
using ll = long long;

//Tags: 主客転倒, シグマ計算
//Level: 2.5
//前数列m^n通りのf(a1, a2)から答えに加わる寄与を求める。対称性からそのnC2倍が答え。
//(a1, a2)は(0, 0)から(m-1, m-1)まである(全部でm^2通り)が、
//a1=i, a2=jとなる数列はi, jの値によらす全部でm^(n-2)通りある。
//ゆえに、f(a1, a2)からの寄与は、(f(0, 0)+...+f(m-1, m-1))*m^(n-2)である。
//iの値によらず、f(i, 0), f(i, 1), ..., f(i, m-1)には0からm-1が一回ずつ現れるから、この和はm*(m-1)/2。
//よって、f(a1, a2)からの寄与は、m^2*(m-1)/2*m^(n-2)=m^n*(m-1)/2。
//以上より答えは、nC2*m^n*(m-1)/2=m^n*n(n-1)*m(m-1)/4。

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


mint inv4=mint(1)/4;
void solve(){
  ll n, m; cin >> n >> m;
  mint ans=mint(n)*(n-1)*mint(m).pow(n)*(m-1)*inv4;
  cout << ans << endl;
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}