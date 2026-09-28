#include<iostream>
#include<vector>
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

int main(void){
  int n, P, Q, m; cin >> n >> P >> Q >> m;
  vector<int> l(n), r(n);
  for(int i=0; i<n; i++) cin >> l[i] >> r[i];
  int cf=60, M=121, X=4;
  auto solve=[&](){
    vector dp(X, vector(X, vector<mint>(M)));
    dp[0][0][cf]=1;
    for(int i=0; i<n; i++){
      vector imos(X, vector(X, vector<mint>(M+1, 0)));
      for(int p=0; p<X; p++)for(int q=0; q<X; q++){
        for(int d=0; d<M; d++){
          if(p+1<X&&d+l[i]<M){
            int nl=d+l[i], nr=min(d+r[i]+1, M);
            imos[p+1][q][nl]+=dp[p][q][d];
            imos[p+1][q][nr]-=dp[p][q][d];
          }
          if(q+1<X&&d-l[i]>=0){
            int nl=max(0, d-r[i]), nr=min(d-l[i]+1, M);
            imos[p][q+1][nl]+=dp[p][q][d];
            imos[p][q+1][nr]-=dp[p][q][d];
          }
        }
      }
      for(int p=0; p<X; p++)for(int q=0; q<X; q++){
        for(int d=0; d<M; d++){
          imos[p][q][d+1]+=imos[p][q][d];
        }
      }
      for(int p=0; p<X; p++)for(int q=0; q<X; q++){
        for(int d=0; d<M; d++) dp[p][q][d]+=imos[p][q][d];
      }
    }
    cout << dp[P][Q][cf] << '\n';
  };
  while(m--){
    int x, a, b; cin >> x >> a >> b; x--;
    l[x]=a, r[x]=b;
    solve();
  }
  return 0; 
}