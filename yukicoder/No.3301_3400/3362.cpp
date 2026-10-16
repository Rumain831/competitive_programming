#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 数学, 四則演算
//Level: 1.5

struct frac{
  ll bunsi, bumbo;
  frac(ll a, ll b=1):bunsi(a), bumbo(b){
    normalize();
  }

  ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b, a%b);
  }

  void normalize(){
    if(bumbo<0) bunsi*=-1, bumbo*=-1;
    ll g=gcd(abs(bunsi), abs(bumbo));
    bunsi/=g, bumbo/=g;
  }
  
  frac& operator+=(const frac& other){
    bunsi=bunsi*other.bumbo+other.bunsi*bumbo;
    bumbo*=other.bumbo;
    normalize();
    return *this;
  }
  frac& operator-=(const frac& other){
    bunsi=bunsi*other.bumbo-other.bunsi*bumbo;
    bumbo*=other.bumbo;
    normalize();
    return *this;
  }
  frac& operator*=(const frac& other){
    bunsi*=other.bunsi;
    bumbo*=other.bumbo;
    normalize();
    return *this;
  }
  frac& operator/=(const frac& other){
    bunsi*=other.bumbo;
    bumbo*=other.bunsi;
    normalize();
    return *this;
  }

  frac operator+()const{
    return *this;
  }
  frac operator-()const{
    return frac(-bunsi, bumbo);
  }

  frac operator+(const frac& other)const{
    frac ans=*this;
    return ans+=other;
  }
  frac operator-(const frac& other)const{
    frac ans=*this;
    return ans-=other;
  }
  frac operator*(const frac& other)const{
    frac ans=*this;
    return ans*=other;
  }
  frac operator/(const frac& other)const{
    frac ans=*this;
    return ans/=other;
  }

  bool operator==(const frac& other)const{
    return bunsi==other.bunsi&&bumbo==other.bumbo;
  }
  bool operator!=(const frac& other)const{
    return !(*this==other);
  }
  bool operator<(const frac& other)const{
    return (__int128)bunsi*other.bumbo<(__int128)other.bunsi*bumbo;
  }
  bool operator>(const frac& other) const {
    return other<*this;
  }
  bool operator<=(const frac& other)const{
    return !(*this>other);
  }
  bool operator>=(const frac& other)const{
    return !(*this<other);
  }

  friend ostream& operator<<(ostream& os, const frac& f){
    if (f.bumbo == 1) os << f.bunsi;
    else os << f.bunsi << "/" << f.bumbo;
    return os;
  }
};

ll f(ll p, ll q){
  if(p>=0) return p/q;
  else{
    ll pp=-p;
    return -(pp+q-1)/q;
  }
}

int main(void){
  int n, a, b; cin >> n >> a >> b;
  vector<ll> k(n+1), pa(n+2, 1), pb(n+2, 1);
  for(auto&x:k) cin >> x;
  for(int i=1; i<n+2; i++) pa[i]=pa[i-1]*a, pb[i]=pb[i-1]*b;
  frac ans(0, 1);
  for(int i=0; i<=n; i++){
    frac now(k[i]*(pb[i+1]-pa[i+1]), i+1);
    ans+=now;
  }
  ll p=ans.bunsi, q=ans.bumbo;
  cout << f(p, q) << endl;
  return 0; 
}