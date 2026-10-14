#include<iostream>
using namespace std;
using ll = long long;

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

int main(void){
  
}