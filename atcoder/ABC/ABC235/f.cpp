#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 桁dp

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
  string n; int m; cin >> n >> m;
  int tar=0;
  for(int i=0; i<m; i++){
    int c; cin >> c;
    tar|=(1<<c);
  }
  int d=n.size();
  int mx=(1<<10);
  vector dp(d+1, vector(2, vector<mint>(mx)));
  vector sum(d+1, vector(2, vector<mint>(mx)));
  dp[0][0][0]=1;
  vector<mint> ten(d+1, 1);
  for(int i=1; i<=d; i++) ten[i]=ten[i-1]*10;
  for(int i=0; i<d; i++){
    int now=n[i]-'0';
    for(int ika=0; ika<2; ika++)for(int p=0; p<mx; p++){
      int r=(ika?9:now);
      for(int x=0; x<=r; x++){
        int np=(p|(1<<x));
        int nika=(ika|(x<now));
        if(p==0&&x==0) np=0;
        dp[i+1][nika][np]+=dp[i][ika][p];
        sum[i+1][nika][np]+=sum[i][ika][p]+x*ten[d-i-1]*dp[i][ika][p];
      }
    }
  }
  mint ans=0;
  for(int i=0; i<mx; i++){
    if((i&tar)==tar) ans+=sum[d][0][i]+sum[d][1][i];
  }
  cout << ans << endl;
  return 0; 
}