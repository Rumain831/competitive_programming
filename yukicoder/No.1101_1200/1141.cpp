#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 整数, grid, コーナーケース
//Level: 2.5

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
  int h, w; cin >> h >> w;
  vector a(h, vector<mint>(w));
  vector<mint> tate(h, 1), yoko(w, 1);
  vector<int> t0(h), y0(w);
  mint all=1;
  int a0=0;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    cin >> a[i][j];
    if(a[i][j]==0) t0[i]++, y0[j]++, a0++;
    mint x=(a[i][j]==0?1:a[i][j]);
    tate[i]*=x, yoko[j]*=x;
    all*=x;
  }
  int q; cin >> q;
  while(q--){
    int r, c; cin >> r >> c; r--, c--;
    int zero=a0-(t0[r]+y0[c]-(a[r][c]==0));
    if(zero) cout << 0 << '\n';
    else{
      mint ans=all/(tate[r]*yoko[c])*(a[r][c]==0?1:a[r][c]);
      cout << ans << '\n';
    }
  }
  return 0; 
}