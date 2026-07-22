#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: dp, 主客転倒

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
  string s; cin >> s;
  //式の個数, 式の結果の総和, 各式で最後に足される値の総和
  mint dp[3]={1, s[0]-'0', s[0]-'0'};
  int n=s.size();
  for(int i=1; i<n; i++){
    int now=s[i]-'0';
    mint old[3]={0, 0, 0};
    swap(old, dp);
    dp[0]=old[0]*2;
    //+を付けてsiを足す・・・old[1]+old[0]*si
    //直前の項にsiを続ける・・・old[1]-old[2]+10*old[2]+old[0]*si
    dp[1]=old[0]*2*now+old[1]*2+old[2]*9;
    //+を付けてsiを足す・・・old[0]*si
    //直前の項にsiを続ける・・・10*old[2]+old[0]*si
    dp[2]=old[0]*2*now+old[2]*10;
  }
  cout << dp[1] << endl;
  return 0; 
}