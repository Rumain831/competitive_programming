#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
const ll MOD=998244353;

//Tags: 主客転倒, グラフ
//Level: 3
//辺を固定したとき、答えへの寄与は、(0を含む部分の頂点数)*(腕の残り)

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
  mint sum=1, inv2=mint(1)/2, inv6=mint(1)/6;
  mint ans=0, arithsum=0;
  auto S1=[&](mint x){return x*(x+1)*inv2;};
  auto S2=[&](mint x){return x*(x+1)*(2*x+1)*inv6;};
  vector<mint> Y(n);
  for(auto&x:Y) cin >> x, sum+=x;
  for(int i=0; i<n; i++){
    mint y=Y[i], rem=sum-y;
    //x=0 ~ y-1
    //(rem+x)*(y-x)=rem*y+(y-rem)x-x^2
    ans+=rem*y*y+(y-rem)*S1(y-1)-S2(y-1);
  }
  cout << ans << endl;
  return 0; 
}