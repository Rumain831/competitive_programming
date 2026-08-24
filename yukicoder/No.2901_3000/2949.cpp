#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: DFS
//Level: 2.5
//LCAを全部試している
//自分がパスの端になるものと、自分で曲がる部分をそれぞれ求めている。

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
  vector<mint> a(n);
  for(auto&x:a) cin >> x;
  vector<vector<int>> to(n);
  for(int i=0; i<n-1; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v); swap(u, v);
    to[u].push_back(v);
  }
  mint ans=0, rev2=mint(1)/2;
  auto dfs=[&](auto dfs, int now, int par=-1)->mint {
    mint sum=0, sq=0;
    for(auto p:to[now])if(p!=par){
      mint x=dfs(dfs, p, now);
      sum+=x, sq+=x*x;
    }
    ans+=sum*a[now];
    ans+=(sum*sum-sq)*rev2*a[now];
    sum*=a[now], sum+=a[now];
    return sum;
  };
  dfs(dfs, 0);
  cout << ans << endl;
  return 0; 
}