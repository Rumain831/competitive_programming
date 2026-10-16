#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: dp, 累積和, 数え上げ
//Level: 2.5

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
  int n, m, k; cin >> n >> m >> k;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  sort(begin(a), end(a));
  vector<int> l(n), r(n);
  for(int i=0; i<n; i++){
    l[i]=lower_bound(begin(a), end(a), a[i]-k)-begin(a);
    r[i]=upper_bound(begin(a), end(a), a[i]+k)-begin(a);
  }
  vector<mint> dp(n), sum(n+1);
  for(int i=0; i<n; i++) dp[i]=1, sum[i+1]=sum[i]+dp[i];
  for(int i=1; i<m; i++){
    vector<mint> old(n), oldsum(n+1);
    swap(old, dp);
    swap(oldsum, sum);
    for(int j=0; j<n; j++) dp[j]=oldsum[r[j]]-oldsum[l[j]];
    for(int j=0; j<n; j++) sum[j+1]=sum[j]+dp[j];
  } 
  mint ans=0;
  for(int i=0; i<n; i++) ans+=dp[i];
  cout << ans << endl;
  return 0; 
}