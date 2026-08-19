#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

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

mint dp[5001][2][11][10];
mint f(string& s){
  mint ans=0;
  int d=s.size();
  for(int i=0; i<=d; i++)for(int j=0; j<2; j++)for(int k=0; k<11; k++)for(int l=0; l<10; l++) dp[i][j][k][l]=0;
  dp[0][0][10][0]=1;
  for(int i=0; i<d; i++){
    int now=s[i]-'0';
    for(int ika=0; ika<2; ika++)for(int e=0; e<11; e++)for(int last=0; last<10; last++){
      int r=(ika?9:now);
      for(int x=0; x<=r; x++){
        int nika=(ika||x<now);
        int ne=abs(last-x);
        int nlast=x;
        if(e<10&&e>ne) continue;
        if(e==10){
          if(x==0) ne=10;
          else ne=0;
        }
        dp[i+1][nika][ne][nlast]+=dp[i][ika][e][last];
      }
    }
  }
  for(int i=0; i<2; i++)for(int j=0; j<=10; j++)for(int k=0; k<10; k++){
    ans+=dp[d][i][j][k];
  }
  return ans;
};

int smooth(string& s){
  int d=s.size();
  if(d<=2) return 1;
  for(int i=0; i<d-2; i++){
    int e1=abs(s[i]-s[i+1]);
    int e2=abs(s[i+1]-s[i+2]);
    if(e1>e2) return 0;
  }
  return 1;
}

int main(void){
  string l, r; cin >> l >> r;
  mint ans=smooth(l)+f(r)-f(l);
  cout << ans << endl;
  return 0; 
}